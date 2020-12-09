n, k  = map(int, input().split())
a = list(map(int, input().split()))

s = [0] * (n + 1)
f = [0] * (n + 1)
g = [0] * (n + k + 3)

for i in range(n):
    s[i + 1] +=  s[i] + a[i]

for i in range(k, n + 1):
    f[i] = max(f[i-1], s[i] - s[i-k])

for i in range(n - k + 1, 0, -1):
    g[i] = max(g[i + 1], s[i + k -1] - s[i - 1])

ans = 10 ** 16
for i in range(n):
    ans = min(ans, max(f[i], g[i + k + 1]))

print(ans)