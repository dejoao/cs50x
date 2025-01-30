SELECT AVG(songs.energy)
   ...> AS media_energy
   ...> FROM songs
   ...> JOIN artists ON songs.artist_id = artists.id
   ...> WHERE artists.name = 'Drake';