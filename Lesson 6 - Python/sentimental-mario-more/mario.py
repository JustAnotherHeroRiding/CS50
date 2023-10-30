# TODO
import cs50


heigth = cs50.get_int("Input an integer: ")
while heigth < 0 or heigth >= 8:
    heigth = cs50.get_int("Input an integer: ")
    
    
for i in range(heigth):
    for j in range(heigth):
        j = heigth - i - 1
        print(" ")
    for k in range(heigth):
        k = i + 1
        print("#")
    print("  ")
    for l in range(heigth):
        l = i + 1
        print("#")
