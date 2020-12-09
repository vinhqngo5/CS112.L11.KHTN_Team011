n = int(input())

res, mod = (n // 3) * 7, n % 3
if (mod == 1):
    res = res - 7 + 4
elif (mod == 2):
    res += 1
print (res)