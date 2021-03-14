-- List the titles of all movies in which both Johnny Depp and Helena Bonham Carter starred.
-- Your query should output a table with a single column for the title of each movie.
-- You may assume that there is only one person in the database with the name Johnny Depp.
-- You may assume that there is only one person in the database with the name Helena Bonham Carter.
-- Executing 12.sql results in a table with 1 column and 6 rows.

SELECT title FROM 
stars JOIN movies ON stars.movie_id = movies.id
WHERE person_id IN
(SELECT id FROM people WHERE name IN ("Johnny Depp", "Helena Bonham Carter"))
GROUP BY title
HAVING COUNT(title) > 1