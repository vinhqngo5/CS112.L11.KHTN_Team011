a = str(input())
b = str(input())

diction = {}
for i in range(len(a)-1):
    sub_str = a[i] + a[i+1]
    if sub_str in diction:
        diction[sub_str] += 1
    else:
        diction[sub_str] = 1

res = 0
for i in range(len(b)-1):
    sub_str = b[i] + b[i+1]
    if sub_str in diction:
        res += diction[sub_str]
        diction[sub_str] = 0

print(res)