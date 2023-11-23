## For each of the following problems, you should write a single SQL query that outputs the
# results specified by each problem. Your response must take the form of a single SQL query,
# though you may nest other queries inside of your query. You should not assume anything about the ids of any
# particular songs or artists: your queries should be accurate even if the id of any particular song or person were different.
# Finally, each query should return only the data necessary to answer the question: if the problem only asks you to output the names
# of songs, for example, then your query should not also output each song’s tempo.
from cs50 import SQL
import csv

db = SQL("sqlite:///songs.db")

##all = db.execute("SELECT * FROM songs")

## In 1.sql, write a SQL query to list the names of all songs in the database.
## Your query should output a table with a single column for the name of each song.

##allSongNames = db.execute("SELECT name FROM songs")

## In 2.sql, write a SQL query to list the names of all songs in increasing order of tempo.
## Your query should output a table with a single column for the name of each song.

##sortedByTempo = db.execute("SELECT name FROM songs ORDER BY tempo")

## In 3.sql, write a SQL query to list the names of the top 5 longest songs, in descending order of length.
## Your query should output a table with a single column for the name of each song.

#sortedByLength = db.execute("SELECT name FROM songs ORDER BY duration_ms DESC LIMIT 5")

## In 4.sql, write a SQL query that lists the names of any songs that have danceability, energy, and valence greater than 0.75.
## Your query should output a table with a single column for the name of each song.

#above3Quarters = db.execute("SELECT name, danceability, energy, valence FROM songs WHERE danceability > 0.75 AND energy > 0.75 AND valence > 0.75")


## In 5.sql, write a SQL query that returns the average energy of all the songs.
## Your query should output a table with a single column and a single row containing the average energy.

# averageEnergy = db.execute("SELECT AVG(energy) FROM songs")

## In 6.sql, write a SQL query that lists the names of songs that are by Post Malone.
## Your query should output a table with a single column for the name of each song.
## You should not make any assumptions about what Post Malone’s artist_id is.

# Here we need to use the artist_id column to find the name in the artists table and see if it matches Post Malone's id
#postMalone = db.execute("SELECT name FROM songs WHERE artist_id = (SELECT id FROM artists WHERE name = 'Post Malone')")

## In 7.sql, write a SQL query that returns the average energy of songs that are by Drake.
## Your query should output a table with a single column and a single row containing the average energy.
## You should not make any assumptions about what Drake’s artist_id is.

#drakeEnergy = db.execute("SELECT AVG(energy) FROM songs WHERE artist_id = (SELECT id FROM artists WHERE name = 'Drake')")

## In 8.sql, write a SQL query that lists the names of the songs that feature other artists.
## Songs that feature other artists will include “feat.” in the name of the song.
## Your query should output a table with a single column for the name of each song.

#features = db.execute("SELECT name FROM songs WHERE name LIKE '%feat.%'")
