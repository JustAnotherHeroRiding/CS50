# TODO
import re


def luhn_check(length, number):
    result = 0
    alternate = False

    for i in range(length - 1, -1, -1):
        digit = int(number[i])
        if alternate:
            product = digit * 2
            if product >= 10:
                result += (product % 10) + (product // 10)
            else:
                result += product
        else:
            result += digit
        alternate = not alternate
    if result % 10 == 0:
        return True
    else:
        return False


def check_card(number, length):
    if (length < 13 or length > 16) or not luhn_check(length, number):
        print("INVALID")
    elif number[0] == "4":
        print("VISA")
    elif number[0] == '5' and (number[1] == '1' or number[1] == '2' or number[1] == '3' or number[1] == '4' or number[1] == '5'):
        print("MASTERCARD")
    elif number[0] == '3' and (number[1] == '4' or number[1] == '7'):
        print("AMEX")
    else:
        print("INVALID")

def is_integer(s):
    # This regex pattern checks for optional negative sign followed by digits
    pattern = r"^-?\d+$"
    return re.match(pattern, s) is not None

number = input("Number: ")

# Keep asking for input until a valid number is entered
while not is_integer(number):
    number = input("Number: ")