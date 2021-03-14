-- List the names of all people who starred in Toy Story.
-- Your query should output a table with a single column for the name of each person.
-- You may assume that there is only one movie in the database with the title Toy Story.
-- Executing 8.sql results in a table with 1 column and 4 rows.

SELECT name from people WHERE id IN
(SELECT person_id FROM
movies JOIN stars ON movies.id = stars.movie_id
WHERE title = "Toy Story")