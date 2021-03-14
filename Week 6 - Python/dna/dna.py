import csv
import sys

if len(sys.argv) != 3:
    print("Usage: dna.py database/DATA.csv sequences/SEQ.txt")
    sys.exit()

# Creating lists to store data in
STRs = []
names = []
data = []

# Import the data file
with open(sys.argv[1], newline='') as database:
    reader = csv.reader(database)

    # ========== using name as dicts ==================
    header = next(reader)
    # Creating list of STRs in database
    for i in range(1, len(header)):
        STRs.append(header[i])

    # Creating list of names
    for row in reader:
        names.append(row[0])
        data.append(row[1:])

# Import the sequence file
with open(sys.argv[2], newline='') as sequence:
    reader = csv.reader(sequence)
    for row in reader:
        seq = row[0]

# # names is names
# print(names)
# # STRs is a list of the STRs available in the database file
# print(STRs)
# # data is a list of lists, containing each row of the database file
# print(data)
# # seq is the STR to check against the dictionaries
# print(seq)

# if [value n from row] * [STR] in sequence :    // the substring is in the sequence

numSTRs = len(STRs)  # Number of STRs to compare
numData = len(data)  # Number of rows of data to compare

# Iterate through each row
for row in range(numData):
    flag = False
    count = 0   # number of matches of STR for each person to seq

    # Iterate through each column of data to find (max value of consecutive STR) * STR and compare it to seq
    for col in range(numSTRs):

        if (int(data[row][col]) * STRs[col]) in seq:
            # need to check if the .txt STR repeats more than the max in the data STR
            if ((int(data[row][col]) + 1) * STRs[col]) in seq:  # n * STR, (n + 1) * STR ... all included, remove (n+1) * STR onwards
                break
            else:
                count += 1
        else:
            break

    # count == numSTRs means that all match
    if count == numSTRs:
        index = row
        flag = True
        break

# if flag is True, then print name
if flag:
    print(names[index])
else:
    print("No match")