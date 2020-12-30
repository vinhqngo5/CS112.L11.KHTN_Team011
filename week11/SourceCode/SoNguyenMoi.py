string = input()
sum = 0
for character in string:
    sum += int(character)
plus = 3 - sum % 3
minus = sum % 3 
pos, num = 0, 0
if (minus == 0):
    minus = 3
for character_pos in range(len(string)):
    can_be_added = False
    i = int(string[character_pos])
    if (i + plus <= 9):
        i += plus
        while (i + 3 <= 9):
            i += 3
        can_be_added = True
    if (can_be_added):
        pos = character_pos
        num = i
        break
if (can_be_added):
    print(string[:pos] + str(num) + string[pos + 1:])
else:
    print(string[:-1] + str(int(string[-1]) - minus))