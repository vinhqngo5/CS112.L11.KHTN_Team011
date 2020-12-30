a = int(input())
b = int(input())

c = a + b

def removeZero(n):
    newNumber = 0
    power10 = 1
    while (n > 0):
        lastDigit = n % 10
        if (lastDigit):
            newNumber += lastDigit * power10
            power10 = power10 * 10;
        n = n // 10
    return newNumber

new_a = removeZero(a)
new_b = removeZero(b)
new_c = removeZero(c)

if (new_a + new_b == new_c):
    print('YES')
else:
    print('NO')
