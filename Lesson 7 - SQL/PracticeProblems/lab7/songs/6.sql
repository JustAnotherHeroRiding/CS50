SELECT name FROM songs WHERE artist_id = (SELECT id FROm artists WHERE name = 'Post Malone');