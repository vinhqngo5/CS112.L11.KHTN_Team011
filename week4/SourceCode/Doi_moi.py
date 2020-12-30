a, k, b, m, n = map(int, input().split())

l, r, ans = 1, n, 0
while (l <= r):
    mid = (l + r) // 2
    day = mid * a - (mid // k) * a + mid * b - (mid // m) * b
    if (day >= n):
        r = mid - 1
        ans = mid
    else:
        l = mid + 1

print(ans)