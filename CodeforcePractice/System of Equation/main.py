n, m = map(int, input().split())

def check(i, j, n, m):
    a = (i * i + j) == n
    b = (i + j * j) == m
    return (a and b)

count = 0

for i in range(n + 1):
    for j in range(m + 1):
        if (check(i, j, n, m)):
            count = count + 1
print(count)
