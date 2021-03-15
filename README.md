# CS50

A repository for my CS50x 2020 assignments. 

## Week 0
### PingPong.sb3
A simple 2-player 2D PingPong game. Use 'W'/'S' or the Up/Down arrow keys to move the Blue and Red paddle respectively. The first player to reach 10 points win, ending the game. Alternatively, Spacebar can be used to end the game.  
Game can be played at https://scratch.mit.edu/.  


## Week 1
Programs in C were written on CS50 IDE, a cloud-based programming environment https://ide.cs50.io/.  
### hello.c
A simple program in C to ask for a name and printing a personalised greeting message back to the user.  
  
### mario.c
A program in C to get user input for variable height, creating a pyramid of indicated height using '#'.  

### cash.c
A program in C that outputs the smallest number of coins required to make change for the amount the user indicates. The coins available consists of quarters (25¢), dimes (10¢), nickels (5¢), and pennies (1¢). This is based on the Greedy algorithm. The Greedy algorithm always takes the best immediate, or local, solution while finding an answer. (Essentially finding the fastest way of reducing the indicated change to 0 without making a loss)  

### credit.c
A program in C to check the validity of American Express(AMEX), MasterCard and VISA credit cards. AMEX uses 15-digit numbers, MasterCard uses 16-digit numbers, and Visa uses 13- and 16-digit numbers. All AMEX numbers start with 34 or 37; most MasterCard numbers start with 51, 52, 53, 54, or 55 (they also have some other potential starting numbers which we won’t concern ourselves with for this problem); and all Visa numbers start with 4. Most cards use an algorithm invented by Hans Peter Luhn of IBM. Luhn’s Algorithm is used in this code to determine if a credit card number is (syntactically) valid.  

Luhn’s Algorithm:
1. Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits (not values) together.
2. Add the sum to the sum of the digits that weren’t multiplied by 2.
3. If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!

The program gets a user input for a credit card number (sans hyphens), then outputs whether the card belongs to AMEX, MasterCard or VISA (based on above conditions), or whether the card number is invalid.


## Week 2
### readability.c
A C program which prompts the user for a string of text where the the number of letters, words, and sentences in the given text would be counted. Any lowercase character from a to z or any uppercase character from A to Z is assumed to be a letter. Any sequence of characters separated by spaces counts as a word, and that any occurrence of a period, exclamation point, or question mark indicates the end of a sentence. 

The program would then print "Grade X" where X is the grade level computed by the Coleman-Liau formula, rounded to the nearest integer.
If the resulting index number is 16 or higher (equivalent to or greater than a senior undergraduate reading level), the output would be "Grade 16+" instead of the exact index number. If the index number is less than 1, the program would output "Before Grade 1".

### caesar.c
The program accepts a single command-line argument, a non-negative integer.
If the program is executed without any command-line arguments or with more than one command-line argument, an error message is printed and return from main a value of 1 immediately.
If any of the characters of the command-line argument is not a decimal digit, the program prints the message "Usage: ./caesar key" and return from main a value of 1.
The program works for all non-negative integral values less than (2^31) - 26. Even if the commnand line argument is greater than 26, the alphabetical characters in the program’s input will remain alphabetical characters in your program’s output. For instance, if the argument is 27, A should not become `[` even though `[` is 27 positions away from A in ASCII, per http://www.asciichart.com/[asciichart.com]; A would become B, since B is 27 positions away from A.
The program first outputs "plaintext: " and then prompt the user for a string of plaintext.
The program then outputs "ciphertext: " followed by the plaintext’s corresponding ciphertext, with each alphabetical character in the plaintext “rotated” by the provided argument integer's positions; non-alphabetical characters should be outputted unchanged.
The program preserves case: capitalized letters, though rotated, must remain capitalized letters; lowercase letters, though rotated, must remain lowercase letters.
After outputting the ciphertext, a newline is printed and exited by returning 0 from main.

### substitution.c
The program accepts a single command-line argument, the key to use for the substitution. The key itself should be case-insensitive, so whether any character in the key is uppercase or lowercase should not affect the behavior of your program.
If the program is executed without any command-line arguments or with more than one command-line argument, an error message would be printed and return from main a value of 1 immediately.
If the key is invalid (as by not containing 26 characters, containing any character that is not an alphabetic character, or not containing each letter exactly once), the program would print an error message and return from main a value of 1 immediately.
The program first outputs "plaintext: " and then prompt the user for a string of plaintext.
The program then outputs "ciphertext: "(without a newline) followed by the plaintext’s corresponding ciphertext, with each alphabetical character in the plaintext substituted for the corresponding character in the ciphertext; non-alphabetical characters should be outputted unchanged.
Case is preserved: capitalized letters must remain capitalized letters; lowercase letters must remain lowercase letters.
After outputting the ciphertext, a newline is printed and exited by returning 0 from main.


## Week 3
### plurality.c
Completed the implementation of plurality.c in such a way that the program simulates a plurality vote election.

Completed the vote function.
vote takes a single argument, a string called name, representing the name of the candidate who was voted for.
If name matches one of the names of the candidates in the election, then update that candidate’s vote total to account for the new vote. The vote function in this case should return true to indicate a successful ballot.
If name does not match the name of any of the candidates in the election, no vote totals should change, and the vote function should return false to indicate an invalid ballot.
Assume that no two candidates will have the same name.

Completed the print_winner function.
The function should print out the name of the candidate who received the most votes in the election, and then print a newline.
It is possible that the election could end in a tie if multiple candidates each have the maximum number of votes. In that case, the names of each of the winning candidates, each on a separate line would be printed.

### runoff.c
Completed the vote function.
The function takes arguments voter, rank, and name. If name is a match for the name of a valid candidate, then you should update the global preferences array to indicate that the voter voter has that candidate as their rank preference (where 0 is the first preference, 1 is the second preference, etc.).
If the preference is successfully recorded, the function should return true; the function should return false otherwise (if, for instance, name is not the name of one of the candidates).
Assume that no two candidates will have the same name.

Completed the tabulate function.
The function should update the number of votes each candidate has at this stage in the runoff.
At each stage in the runoff, every voter effectively votes for their top-preferred candidate who has not already been eliminated.

Completed the print_winner function.
If any candidate has more than half of the vote, their name would be printed to stdout and the function will return true.
If nobody has won the election yet, the function returns false.

Completed the find_min function.
The function returns the minimum vote total for any candidate who is still in the election.

Completed the is_tie function.
The function takes an argument min, which will be the minimum number of votes that anyone in the election currently has.
The function would return true if every candidate remaining in the election has the same number of votes, and return false otherwise.

Completed the eliminate function.
The function takes an argument min, which will be the minimum number of votes that anyone in the election currently has.
The function should eliminate the candidate (or candidates) who have min number of votes.


## Week 4
### filter.c
Implemented the functions in helpers.c such that a user can apply grayscale, sepia, reflection, or blur filters to their images.

The function grayscale should take an image and turn it into a black-and-white version of the same image.
The function sepia should take an image and turn it into a sepia version of the same image.
The reflect function should take an image and reflect it horizontally.
Finally, the blur function should take an image and turn it into a box-blurred version of the same image.
Example: Running "./filter -g images/yard.bmp out.bmp" takes the image at images/yard.bmp, and generates a new image called out.bmp after running the pixels through the grayscale function.

### recover.c
A program called recover that recovers JPEGs from a forensic image.

The program accepts exactly one command-line argument, the name of a forensic image from which to recover JPEGs.
If the program is not executed with exactly one command-line argument, it reminds the user of correct usage, and main should return 1.
If the forensic image cannot be opened for reading, the program would inform the user as much, and main should return 1.


## Week 5
### speller
Implement a program that spell-checks a file, using a hash table.
Implemented, load, hash, size, check, and unload (given files) as efficiently as possible using a hash table in such a way that TIME IN load, TIME IN check, TIME IN size, and TIME IN unload are all minimized. 
The djb2 hash function <http://www.cse.yorku.ca/~oz/hash.html> was implemented to minimize the time taken to spell check a given file.

## Week 6
### hello.py
A simple program in Python to ask for a name and printing a personalised greeting message back to the user.

### mario.py
A program in Python to get user input for variable height, creating a pyramid of indicated height using '#'.  
The program prompts the user for the half-pyramid’s height, a positive integer between 1 and 8, inclusive. 

### cash.py
A program in Python that outputs the smallest number of coins required to make change for the amount the user indicates. The coins available consists of quarters (25¢), dimes (10¢), nickels (5¢), and pennies (1¢). This is based on the Greedy algorithm. The Greedy algorithm always takes the best immediate, or local, solution while finding an answer. (Essentially finding the fastest way of reducing the indicated change to 0 without making a loss)  

### credit.py
A program in Python to check the validity of American Express(AMEX), MasterCard and VISA credit cards. AMEX uses 15-digit numbers, MasterCard uses 16-digit numbers, and Visa uses 13- and 16-digit numbers. All AMEX numbers start with 34 or 37; most MasterCard numbers start with 51, 52, 53, 54, or 55 (they also have some other potential starting numbers which we won’t concern ourselves with for this problem); and all Visa numbers start with 4. Most cards use an algorithm invented by Hans Peter Luhn of IBM. Luhn’s Algorithm is used in this code to determine if a credit card number is (syntactically) valid.  

Luhn’s Algorithm:
1. Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits (not values) together.
2. Add the sum to the sum of the digits that weren’t multiplied by 2.
3. If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!

The program gets a user input for a credit card number (sans hyphens), then outputs whether the card belongs to AMEX, MasterCard or VISA (based on above conditions), or whether the card number is invalid.

### readability.py
A Python program which prompts the user for a string of text where the the number of letters, words, and sentences in the given text would be counted. Any lowercase character from a to z or any uppercase character from A to Z is assumed to be a letter. Any sequence of characters separated by spaces counts as a word, and that any occurrence of a period, exclamation point, or question mark indicates the end of a sentence. 

The program would then print "Grade X" where X is the grade level computed by the Coleman-Liau formula, rounded to the nearest integer.
If the resulting index number is 16 or higher (equivalent to or greater than a senior undergraduate reading level), the output would be "Grade 16+" instead of the exact index number. If the index number is less than 1, the program would output "Before Grade 1".

### dna.py
A Python program that identifies a person based on their DNA sequence.
The program requires its first command-line argument the name of a CSV file containing the STR counts for a list of individuals and should require as its second command-line argument the name of a text file containing the DNA sequence to identify.
If the program is executed with the incorrect number of command-line arguments, it will print an error message. If the correct number of arguments are provided, it is assumed that the first argument is indeed the filename of a valid CSV file, and that the second argument is the filename of a valid text file.
The program opens the CSV file and read its contents into memory.
It is assumed that the first row of the CSV file will be the column names. The first column will be the word name and the remaining columns will be the STR sequences themselves.
The program then opens the DNA sequence and read its contents into memory.
For each of the STRs (from the first line of the CSV file), the program will compute the longest run of consecutive repeats of the STR in the DNA sequence to identify.
If the STR counts match exactly with any of the individuals in the CSV file, the program prints out the name of the matching individual.
It is assumed that the STR counts will not match more than one individual.
If the STR counts do not match exactly with any of the individuals in the CSV file, "No match" will be printed.


## Week 7
### houses
A Python program to import student data into a database, and then produce class rosters.
import.py: A program that imports data from a CSV spreadsheet.
The program accepts the name of a CSV file as a command-line argument. If the incorrect number of command-line arguments are provided, the program prints an error and exit.
It is assumed that the CSV file exists, and will have columns name, house, and birth.
For each student in the CSV file, the student is inserted into the students table in the students.db database.
The CSV file provided has just a name column, the database has separate columns for first, middle, and last names. Thus, each name is parsed and separated into first, middle, and last names. It is assumed that each person’s name field will contain either two space-separated names (a first and last name) or three space-separated names (a first, middle, and last name). For students without a middle name, their middle name field is left as NULL in the table.

roster.py: A program that prints a list of students for a given house in alphabetical order.
The program accepts the name of a house as a command-line argument. If the incorrect number of command-line arguments are provided, the program prints an error and exit.
The program will query the students table in the students.db database for all of the students in the specified house. It will then print out each student’s full name and birth year (formatted as, e.g., Harry James Potter, born 1980 or Luna Lovegood, born 1981).
Students are ordered by last name. For students with the same last name, they are be ordered by first name.

### movies
SQL queries to answer questions about a database of movies.
1.sql: write a SQL query to list the titles of all movies released in 2008.
2.sql: write a SQL query to determine the birth year of Emma Stone.
3.sql: write a SQL query to list the titles of all movies with a release date on or after 2018, in alphabetical order.
4.sql: write a SQL query to determine the number of movies with an IMDb rating of 10.0.
5.sql: write a SQL query to list the titles and release years of all Harry Potter movies, in chronological order.
6.sql: write a SQL query to determine the average rating of all movies released in 2012.
7.sql: write a SQL query to list all movies released in 2010 and their ratings, in descending order by rating. For movies with the same rating, order them alphabetically by title.
8.sql: write a SQL query to list the names of all people who starred in Toy Story.
9.sql: write a SQL query to list the names of all people who starred in a movie released in 2004, ordered by birth year.
10.sql: write a SQL query to list the names of all people who have directed a movie that received a rating of at least 9.0.
11.sql: write a SQL query to list the titles of the five highest rated movies (in order) that Chadwick Boseman starred in, starting with the highest rated.
12.sql: write a SQL query to list the titles of all movies in which both Johnny Depp and Helena Bonham Carter starred.
13.sql: write a SQL query to list the names of all people who starred in a movie in which Kevin Bacon also starred.
