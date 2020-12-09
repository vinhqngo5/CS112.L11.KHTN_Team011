n = int(input())
a = list(map(int, input().split()))

uoc = []
for i in range(1, n+1):
    if (n % i == 0): uoc.append(i)

f = [0] * (n + 1)
mod = 10**9 + 7

def power(a):
    if (a == 0): return 1
    temp = power(a//2)
    temp = (temp * temp) % mod
    if (a % 2): temp = (temp * 3) % mod
    return temp

def get(l, r):
    return f[r] - f[l-1]

for i in range(n): f[i + 1] = f[i] + power(a[i])


ans = []
for u in uoc:
    check, w = [], [u]
    for i in range(0, n, u):
        temp = get(i + 1, i + u)
        if (temp in check):
            if (temp == check[0]): w[1] += 1
            else: w[2] += 1
        else:
            check.append(temp)
            w.append(1)
            if (len(check) > 2): break

    if (len(check) != 2) : continue
    if (w[1] < w[2]):
        w[1], w[2] = w[2], w[1]
    ans.append(w)
if (len(ans) == 0):
    print(-1)
    exit()
print(len(ans))
for i in ans:
    print(i[0], i[1], i[2])