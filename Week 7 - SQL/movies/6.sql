-- Determine the average rating of all movies released in 2012.
-- A table with a single column and a single row (plus optional header) containing the average rating.

SELECT AVG(rating) FROM
movies JOIN ratings ON movies.id = ratings.movie_id
WHERE year = 2012