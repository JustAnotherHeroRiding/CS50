# TODO
import cs50


height = cs50.get_int("Input an integer: ")
while height < 0 or height >= 8:
    height = cs50.get_int("Input an integer: ")
    
    
for i in range(1, height + 1):
    # This will print the spaces as we start with 1 hash and increase
    # This needs to be in centered
    for j in range(height, i, -1):
        # On the first row, if the height is 5
        # j will be 5 and will print 5 spaces
        # i will be 1
        print(" ", end="")
    # Here we print the first hash block
    # Once again on the first row J is one
    # if i is 1, we will print 1 hash
    # if i is 2, we will print 2 hashes
    for j in range(1, i + 1):
        print("#", end="")
    # Two spaces in the middle
    print("  ", end="")
    # Second hash block
    for j in range(1, i + 1):
        print("#", end="")
    print()
