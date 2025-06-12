from fastapi import FastAPI, Header, HTTPException, Query, Depends
import requests
import os
from dotenv import load_dotenv

load_dotenv()
app = FastAPI()

#API_PASSWORD=mystrongpassword123! for user convinience
API_PASSWORD = os.getenv("API_PASSWORD")
RAPIDAPI_KEY = os.getenv("RAPIDAPI_KEY")
SCRAPPER_HOST = os.getenv("SCRAPPER_HOST")
headers = {
    "x-rapidapi-key": RAPIDAPI_KEY,
    "x-rapidapi-host": SCRAPPER_HOST
}

def verify_password(x_api_key: str = Query(...)):
    if x_api_key != API_PASSWORD:
        raise HTTPException(status_code=401, detail="Unauthorized")

@app.get("/protected-endpoint", dependencies=[Depends(verify_password)])
def protected():
    return {"message": "Access granted"}

@app.get("/lyrics/{name}", dependencies=[Depends(verify_password)])
def get_lyrcis_by_name(name: str):

    search_url = "https://spotify-scraper.p.rapidapi.com/v1/track/search"
    search_querystring = {"name": name}
    search_response = requests.get(search_url, headers=headers, params=search_querystring)
    
    if search_response.status_code != 200:
        return {
                "error ID": "Failed to fetch data", 
                "status_code": search_response.status_code, 
                "response": search_response.text
        }
    
    track_data = search_response.json()
    track_id = track_data.get("id")
    
    if not track_id:
        return {"error": "Track ID not found in search result"}

    song_info = {
        "track_name": track_data.get("name"),
        "artist": track_data.get("artists", [{}])[0].get("name") if track_data.get("artists") else None,
        "album": track_data.get("album", {}).get("name"),
        "share_url": track_data.get("shareUrl")
    }

    lyrics_url = "https://spotify-scraper.p.rapidapi.com/v1/track/lyrics"
    lyrics_querystring = {"trackId": track_id,"format":"lrc"}
    lyrics_response = requests.get(lyrics_url, headers=headers, params=lyrics_querystring)
    
    if lyrics_response.status_code == 200:
        lyrics = lyrics_response.text
    else:
        lyrics = None

    return {
            "song_info": song_info,
            "lyrics": lyrics
    }
