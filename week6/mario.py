from cs50 import get_int

while True:
    size = get_int("Height: ")
    if size > 0 and size < 9:
        break

for i in range(size):
    for j in range(size - i - 1):
        print(" ", end='')
    for q in range(i + 1):
        print("#", end='')
    print("")
