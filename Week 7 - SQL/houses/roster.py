import csv
import sys
from cs50 import SQL

db = SQL("sqlite:///students.db")

# Ensure correct number of command line argument provided
if len(sys.argv) != 2:
    print("Usage: python roster.py HOUSE")
    sys.exit()

houses = ["Gryffindor", "Slytherin", "Ravenclaw", "Hufflepuff"]
house = sys.argv[1].title()

if house not in houses:
    print("No such house.")
    sys.exit()

# Writing the query
query = "SELECT first, middle, last, birth FROM students WHERE house = \"" + house + "\"" + "ORDER BY last, first"

# Saving the list of dictionary into variable named roster
roster = db.execute(query)

# Print out results
for i in range(len(roster)):

    if roster[i]['middle'] != None:
        print(roster[i]['first'], roster[i]['middle'], roster[i]['last'] + ", born", roster[i]['birth'])
    else:
        print(roster[i]['first'], roster[i]['last'] + ", born", roster[i]['birth'])