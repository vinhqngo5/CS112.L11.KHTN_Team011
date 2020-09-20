n = int(input())
a, c = input().split()
a, b = [int(x) for x in a.split('/')]
c, d = [int(x) for x in c.split('/')]

data = [[0, 0]] * (n+1)

for i in range(n):
      INP = input()
      X, Y = INP.split()
      X, Y = int(X), int(Y)
      data[i] = [X, Y]

def check(a, b, m, n, x, y):
      if (a[0] == b[0]):
            return (x == 0)
      temp = (a[1] - b[1]) / (a[0] - b[0])
      if (y == 0):
            y = 100000
      else:
            y = x / y
      x = m / n
      return x < temp < y

data = sorted(data, reverse=True)
dp = [0] * (n+1) 
for i in range(1, n+1):
      for j in range(i):
            if check(data[i], data[j], a, b, c , d):
                  dp[i] = max(dp[i], dp[j] + 1)
print(dp[n])
