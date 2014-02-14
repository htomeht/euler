file = open("numbers")

list_of_numbers = []

for n in file:
    list_of_numbers.append(str(n)[::-1])
    print n

length = len(list_of_numbers[0])
carry = 0
new_numbers = []
final = [0]*10

i = 0

try:
    while i < length:
        sum = 0
        for n in list_of_numbers:
            sum += int(n[0])
            new_numbers.append(n[1:])
        list_of_numbers = new_numbers
        new_numbers = []
        sum += carry
        carry = sum/10
except IndexError:
    pass

print list_of_numbers
