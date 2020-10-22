def calculate_ans(sum, mod_one, mod_two, count):
    if (sum % 3 == 2):
        mod_one, mod_two = mod_two, mod_one
    for i in mod_one:
        if count[i] > 0:
            count[i] -= 1
            break
    else:
        delete = 2
        for i in mod_two:
            if count[i] >= 2:
                count[i] -= 2
                delete -= 2
            elif count[i] == 1:
                count[i] -= 1
                delete -= 1
            if delete == 0:
                break


key = input().strip()
sum, count, mod_two, mod_one = 0, [0] * 10, [2, 5, 8], [1, 4, 7]

for i in key:
    j = int(i)
    sum += j
    count[j] += 1
if (sum % 3 != 0):
    calculate_ans(sum, mod_one, mod_two, count)

key = ''
for i in range(10):
    key += str(i) * count[i]

print(key[::-1])