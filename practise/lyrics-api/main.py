import os
import requests
from fastapi import FastAPI
from dotenv import load_dotenv

load_dotenv()

app = FastAPI()

RAPIDAPI_KEY = os.getenv("RAPIDAPI_KEY")
RAPIDAPI_HOST = "genius-song-lyrics1.p.rapidapi.com"

HEADERS = {
    "x-rapidapi-key": RAPIDAPI_KEY,
    "x-rapidapi-host": RAPIDAPI_HOST,
}

@app.get("/recommendations_by_name/")
def recommendations_by_name(song_name: str):
    search_url = f"https://{RAPIDAPI_HOST}/search/"
    params = {"q": song_name}
    search_response = requests.get(search_url, headers=HEADERS, params=params)
    if search_response.status_code != 200:
        return {"error": f"Search API failed with status {search_response.status_code}"}

    search_data = search_response.json()
    hits = search_data.get("hits", [])
    if not hits:
        return {"error": "Song not found"}

    song_id = hits[0]["result"]["id"]

    rec_url = f"https://{RAPIDAPI_HOST}/song/recommendations/"
    rec_params = {"id": song_id}
    rec_response = requests.get(rec_url, headers=HEADERS, params=rec_params)
    if rec_response.status_code != 200:
        return {"error": f"Recommendations API failed with status {rec_response.status_code}"}

    return rec_response.json()
