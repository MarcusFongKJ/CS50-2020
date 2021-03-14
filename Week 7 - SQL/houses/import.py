import csv
import sys
from cs50 import SQL

# Ensure correct number of command line argument provided
if len(sys.argv) != 2:
    print("Usage: python import.py data.csv")
    sys.exit()

# Link SQL and students.db
db = SQL("sqlite:///students.db")

# Create table called students in database file called students.db
# db.execute("CREATE TABLE students (first TEXT, middle TEXT, last TEXT, house TEXT, birth NUMERIC)")

# Open csv file
with open(sys.argv[1], newline='') as database:

    reader = csv.reader(database)
    # Skip the header
    next(reader)

    for row in reader:
        name = row[0]
        house = row[1]
        birth = row[2]

        # Split the name into a list
        name = name.split()
        first = name[0]
        last = name[-1]

        # if len(name) != 2, then there is middle name
        if len(name) != 2:
            middle = name[1]

        else:
            middle = None

        db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                   first, middle, last, house, birth)