from fastapi import FastAPI
import requests
import os
import xml.etree.ElementTree as ET
from dotenv import load_dotenv

load_dotenv()

app = FastAPI()
@app.get("/")
def get_genius_data():
    GENIUS_KEY = os.getenv("RAPIDAPI_KEY")
    GENIUS_HOST = os.getenv("GENIUS_HOST")

    url = "https://genius-song-lyrics1.p.rapidapi.com/song/recommendations/"

    headers = {
        "x-rapidapi-key": GENIUS_KEY,
        "x-rapidapi-host": GENIUS_HOST
    }

    querystring = {"id":"2396871"}

    response = requests.get(url, headers=headers, params=querystring)
    if response.status_code == 200:
        data = response.json()
        recs = data.get("song_recommendations", {}).get("recommendations", [])
        
        # Extract minimal info for each recommended song
        simplified = []
        for rec in recs:
            song = rec.get("recommended_song", {})
            simplified.append({
                "title": song.get("title"),
                "artist": song.get("primary_artist_names"),
                "url": f"https://genius.com{song.get('path')}"
            })
        return {"recommendations": simplified}
    else:
        return {"error": "Failed to fetch data", "status_code": response.status_code}
