from cs50 import SQL
import csv

db = SQL("sqlite:///movies.db")


# In 1.sql, write a SQL query to list the titles of all movies released in 2008.
# Your query should output a table with a single column for the title of each movie.
#
# allEightMovies = db.execute("SELECT title FROM movies WHERE year = 2008;")
# print(allEightMovies)
#
#
# In 2.sql, write a SQL query to determine the birth year of Emma Stone.
# Your query should output a table with a single column and a single row (not counting the header) containing Emma Stone’s birth year.
# You may assume that there is only one person in the database with the name Emma Stone.
#
# emmaStone = db.execute("SELECT birth FROM people WHERE name = 'Emma Stone';")
# print(emmaStone)
#
# In 3.sql, write a SQL query to list the titles of all movies with a release date on or after 2018, in alphabetical order.
# Your query should output a table with a single column for the title of each movie.
# Movies released in 2018 should be included, as should movies with release dates in the future.
#
# currentMovies = db.execute("SELECT title FROM movies WHERE year >= 2018 ORDER BY title;")
# print(currentMovies)

# In 4.sql, write a SQL query to determine the number of movies with an IMDb rating of 10.0.
# Your query should output a table with a single column and a single row (not counting the header) containing the number of movies with a 10.0 rating.
#
# perfectMovies = db.execute("SELECT title FROM movies WHERE id IN (SELECT movie_id FROM ratings WHERE rating = 10.0);")

# In 5.sql, write a SQL query to list the titles and release years of all Harry Potter movies, in chronological order.
# Your query should output a table with two columns, one for the title of each movie and one for the release year of each movie.
# You may assume that the title of all Harry Potter movies will begin with the words “Harry Potter”, and that if a movie title begins with the words “Harry Potter”, it is a Harry Potter movie.
#

#
# In 6.sql, write a SQL query to determine the average rating of all movies released in 2012.
# Your query should output a table with a single column and a single row (not counting the header) containing the average rating.
#
# averageRating = db.execute("SELECT AVG(rating) FROM ratings WHERE movie_id IN (SELECT id FROM movies WHERE year = 2012);")
#
# In 7.sql, write a SQL query to list all movies released in 2010 and their ratings, in descending order by rating.
# For movies with the same rating, order them alphabetically by title.
# Your query should output a table with two columns, one for the title of each movie and one for the rating of each movie.
# Movies that do not have ratings should not be included in the result.
#
# moviesAndRatings = db.execute("SELECT title, rating FROM movies JOIN ratings ON movies.id = ratings.movie_id WHERE year = 2010 ORDER BY rating DESC, title;")
# print(moviesAndRatings)
#
# In 8.sql, write a SQL query to list the names of all people who
# starred in Toy Story.
# Your query should output a table with a single column for the
# name of each person.
# You may assume that there is only one movie in the database
# with the title Toy Story.
#
# toyStoryCast = db.execute("SELECT name FROM people WHERE id IN
# (SELECT person_id FROM stars WHERE movie_id IN (SELECT id FROM movies WHERE title = 'Toy Story'));")
# print(toyStoryCast)

# In 9.sql, write a SQL query to list the names of all people who starred in a movie released in 2004, ordered by birth year.
# Your query should output a table with a single column for the name of each person.
# People with the same birth year may be listed in any order.
# No need to worry about people who have no birth year listed, so long as those who do have a birth year are listed in order.
# If a person appeared in more than one movie in 2004, they should only appear in your results once.

# orderedByBirthYear = db.execute("SELECT name FROM people WHERE id IN (SELECT person_id FROM stars WHERE movie_id IN
# (SELECT id FROM movies WHERE year = 2004)) ORDER BY birth;")


#
# In 10.sql, write a SQL query to list the names of all people who have directed a movie that received a rating of at least 9.0.
# Your query should output a table with a single column for the name of each person.
# If a person directed more than one movie that received a rating of at least 9.0, they should only appear in your results once.
#
#
# bestDirectors = db.execute("SELECT name FROM people WHERE id IN (SELECT person_id FROM directors WHERE movie_id IN (SELECT id FROM movies WHERE id IN (SELECT movie_id FROM ratings WHERE rating >= 9.0)));")

# In 11.sql, write a SQL query to list the titles of the five highest rated movies (in order)
# that Chadwick Boseman starred in, starting with the highest rated.
# Your query should output a table with a single column for the title of each movie.
# You may assume that there is only one person in the database with the name Chadwick Boseman.
#
# top5Chadwick = db.execute(
#     "SELECT title,rating FROM movies JOIN ratings ON movies.id =
#     ratings.movie_id WHERE id IN (SELECT movie_id FROM stars WHERE person_id IN (SELECT id FROM people WHERE name =
#     'Chadwick Boseman')) ORDER BY rating DESC LIMIT 5;"
# )
#
# In 12.sql, write a SQL query to list the titles of all movies in which both Bradley Cooper and Jennifer Lawrence starred.
# Your query should output a table with a single column for the title of each movie.
# You may assume that there is only one person in the database with the name Bradley Cooper.
# You may assume that there is only one person in the database with the name Jennifer Lawrence.
#
# bradAndLawrence = db.execute(
#     "SELECT title FROM movies WHERE id IN ( SELECT movie_id FROM stars WHERE person_id IN
#     ( SELECT id FROM people WHERE name = 'Bradley Cooper' OR name = 'Jennifer Lawrence'));"
# )

# In 13.sql, write a SQL query to list the names of all people who starred in a movie in which Kevin Bacon also starred.
# Your query should output a table with a single column for the name of each person.
# There may be multiple people named Kevin Bacon in the database. Be sure to only select the Kevin Bacon born in 1958.
# Kevin Bacon himself should not be included in the resulting list.
#

# So i need to return names of people who starred in movies with Kevin Bacon
# the first select statement will select names from people
# these people must be part of the stars whose movie_id is part of the movies where kevin bacon's id is in


