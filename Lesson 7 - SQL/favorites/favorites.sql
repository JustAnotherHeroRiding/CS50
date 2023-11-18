/* This will select only 10 shows */
SELECT * FROM shows LIMIT 10;
/* This will order all shows in alphabetical order and show them starting from a("ASC") */
SELECT * FROM shows ORDER BY title ASC;
/* Updating all shows that start with Parks, without checking what the rest of the text is 
This was the most used command to update the data*/
UPDATE shows SET title = 'Parks and Recreation' WHERE title LIKE 'Parks%';