from cs50 import get_int

# Loops forever until height given is within range
while True:
    height = get_int('Height: ')
    if height in range(1, 9):
        break

# Prints spaces and blocks
for i in range(height):
    print(' ' * (height - i - 1), end='')
    print('#' * (i + 1))
