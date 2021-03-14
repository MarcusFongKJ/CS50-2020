-- SQL query to list the titles and release years of all Harry Potter movies, in chronological order.
-- A table with two columns, one for the title of each movie and one for the release year of each movie.
-- Assumption that the title of all Harry Potter movies begin with the words “Harry Potter”, and that if a movie title begins with the words “Harry Potter”, it is a Harry Potter movie.

SELECT title, year 
FROM movies WHERE title LIKE "Harry Potter%"
ORDER BY year ASC