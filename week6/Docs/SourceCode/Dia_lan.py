n, k = map(int, input().strip().split())
a = list(map(int, input().strip().split()))

if (k >= 12):
    t = a[0]
    for i in a:
        t = (t & i)
    if (t==0):
        print("YES")
    else:
        print("NO")
    
else:
    flag = True
    for i in range(n - k + 1):
        if (flag == False):
            break
        t = a[i]
        for j in range(k):
            t = (t & a[i + j])
        if (t == 0):
            flag = False
            break
    if (flag == False):
          print("YES")
    else:
          print("NO")