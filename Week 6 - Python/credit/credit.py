# Input validation
while True:
    num = input("Number: ")
    try:
        num = int(num)
        break
    except ValueError:
        pass

# Convert back to string to make calculations
num = str(num)

mult = []
add = []
nDigits = len(num)
startingNum = int(num[:2])
visaStart = int(num[0])

x = num[::2]
y = num[1::2]

# if len(num) is even, first value will be x2 values
if nDigits % 2 == 0:

    for i in x:
        mult.append(int(i))
    for j in y:
        add.append(int(j))

# if len(num) is odd, first value will just be summed
else:

    for i in x:
        add.append(int(i))
    for j in y:
        mult.append(int(j))

# every other number from second value from back [stored in mult] (multiply each by 2 then sum digits)
mult_sum = []   # list of values after muliplied by 2
for i in mult:
    test = i * 2
    for j in str(test):
        mult_sum.append(int(j))

mult_total = 0
for i in mult_sum:
    mult_total += i

# every other number from first value from back [stored in add] (sum)
add_total = 0
for i in add:
    add_total += i

checksum = mult_total + add_total

# Check checksum to ensure validity
if (checksum % 10 != 0):
    print("INVALID")

else:

    if (nDigits == 15) or (nDigits == 16) or (nDigits == 13):

        # AMEX start with 34 or 37
        if (startingNum == 34) or (startingNum == 37):
            print("AMEX")

        # MasterCard numbers start with 51, 52, 53, 54, or 55 (other potential starting numbers are not of concern in the question)
        elif (startingNum == 51) or (startingNum == 52) or (startingNum == 53) or (startingNum == 54) or (startingNum == 55):
            print("MASTERCARD")

        # Visa numbers start with 4
        else:
            if visaStart == 4:
                print("VISA")
            else:
                print("INVALID")

    else:
        print("INVALID")