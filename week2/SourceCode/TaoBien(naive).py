n, k = map(int, input().split())
a, b, mod = n, n, 1000000007
for i in range(k):
    b = (a + b) % mod
    a = (a + b) % mod
print(b)