from cs50 import get_int
import re

number = get_int("Number: ")

# Converts number to a string
number = str(number)

# Checksum
checksum = int(0)

# Doubles every other digit starting from the second-to-last
for i in range(len(number) - 2, -1, -2):
    m = int(number[i]) * 2
    checksum += m // 10 + m % 10  # Adds digits of product

# Adds remaining digits
for i in range(len(number) - 1, -1, -2):
    checksum += int(number[i])

# Validate number
if checksum % 10 == 0:
    if len(number) == 15 and number.startswith(("34", "37")):
        print("AMEX")

    elif len(number) == 16 and number.startswith(("51", "52", "53", "54", "55")):
        print("MASTERCARD")

    elif len(number) in (13, 16) and number.startswith(("4")):
        print("VISA")
    else:
        print("INVALID")
else:
    print("INVALID")
