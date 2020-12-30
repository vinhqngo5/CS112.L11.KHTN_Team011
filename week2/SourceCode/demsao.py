from sys import stdin, stdout
import bisect

def solveEquation(a, b):
      return -b/a

def uniform(a, b, c, d, X, Y):
      temp = Y - a/b * X
      if (d == 0):
            return temp, X
      pmet = Y - c/d * X
      return temp, solveEquation(c/d, pmet)

n = int(input())
a, c = input().split()
a, b = [int(x) for x in a.split('/')]
c, d = [int(x) for x in c.split('/')]
data = [[0, 0]] * n

for i in range(n):
      X, Y = stdin.readline().split()
      x, y = uniform(a, b, c, d, int(X), int(Y))
      data[i] = [x, y]

data.sort()

lis, len = [0], 1
for i in range(n): 
      if (data[i][0] < 0) or (data[i][1] < 0) or (i != n - 1 and data[i][0] == data[i+1][0]):
            continue
      if (data[i][1] > lis[len-1]): 
            lis.append(data[i][1])
            len += 1
      else: 
            lis[bisect.bisect_left(lis, data[i][1])] = data[i][1]
print(len - 1)
