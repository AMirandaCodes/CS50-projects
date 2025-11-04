from cs50 import get_float

while True:
    change = get_float("Change: ")
    if change > 0:
        break

# Converts dollars to cents (for no rounding errors)
change = round(change * 100)

coins = 0
coin_list = [25, 10, 5, 1]

for coin in coin_list:
    # How many of this coin (integer division)
    coins += change // coin
    # Remaining change
    change %= coin

print(coins)
