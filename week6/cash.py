from cs50 import get_float, get_int

while True:
    change = get_float("Change owed: ")
    if change >= 0.01:
        break

change = round(change * 100) #converte para centavos

coins = 0

while change >= 25:
    change -= 25
    coins += 1

while change >= 10:
    change -= 10
    coins += 1

while change >= 5:
    change -= 5
    coins += 1

while change >= 1:
    change -= 1
    coins += 1

print(f"{coins}")

