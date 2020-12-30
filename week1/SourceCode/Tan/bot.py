n = int(input())
a = list(map(int, input().split()))
sum, ans, l, r, L, R = 0, 0, 0, 0, -1, -1
for i in range(n):
      if (sum + a[i] >= 0):
            sum += a[i]
            if (sum > ans):
                  ans, L, R, r = sum, l, i, i
      else:
            sum, l = 0, i+1
print(L + 1, R + 1, ans)

