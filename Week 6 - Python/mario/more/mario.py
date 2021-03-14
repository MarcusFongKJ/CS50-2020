height = input("Height: ")

# check whether input is digit
while height.isdigit() == False:
    height = input("Height: ")

# check whether input is within range
while int(height) not in range(1, 9):
    height = input("Height: ")

height = int(height)    # convert height to string

for row in range(1, height + 1):   # 1 -> height
    print((height - row) * " ", end="")   # initial spacing
    print(row * "#", end="")  # blocks
    print("  ", end="")  # spacing between the 2 pyramids
    print(row * "#")