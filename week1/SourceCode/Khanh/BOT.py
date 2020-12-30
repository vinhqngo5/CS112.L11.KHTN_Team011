a = int(input())
b = [int(i) for i in input().split()]

x,y,val = 0,len(b)-1,sum(b)

for i in range(0,len(b)):
  sum = 0
  for j in range(i,len(b)):
    sum += b[j]
    if sum > val:
      val = sum
      x = i
      y = j

print(x+1,y+1,val) 