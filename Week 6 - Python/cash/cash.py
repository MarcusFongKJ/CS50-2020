# Get input
while True:
    dollars = input("Change owed: ")
    try:
        change = float(dollars)
        if change > 0:
            break
        else:
            pass
    except ValueError:
        pass

# Convert to cents
cents = round(change * 100)

count = 0

while (cents - 25 >= 0):  # num of 25c coins
    cents -= 25
    count += 1

while (cents - 10 >= 0):  # num of 10c coins
    cents -= 10
    count += 1

while (cents - 5 >= 0):  # num of 5c coins
    cents -= 5
    count += 1

while (cents - 1 >= 0):  # num of 1c coins required to reduce change to 0
    cents -= 1
    count += 1

print(count)