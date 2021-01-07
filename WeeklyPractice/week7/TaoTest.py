from random import randint
from random import choice
import numpy as np

def dia_lan(n,k,a):
    if (k >= 12):
        t = a[0]
        for i in a:
            t = (t & i)
        if (t==0):
            return "YES"
        else:
            return "NO"
    
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
              return "YES"
        else:
              return "NO"

f = open('test.txt','w')
a = []
for i in range (25):
    a.append(randint(1,100))
for i in range (25):
    a.append(randint(100,2000))
for i in range (50):
    a.append(randint(2000,20000))

k = []
test = []

i = 0
while i < 100:
    kq = np.random.choice(["YES","NO"],1,[0.2,0.8])
    t = randint(1,a[i])
    k.append(t)
    test.append([])
    for j in range(a[i]):
        test[i].append(randint(0,2**12))
    if dia_lan(a[i],k[i],test[i]) == kq:
        i +=1
for i in range(100):
    print(a[i],k[i])
    print(test[i])
    res = dia_lan(a[i],k[i],test[i])
    print(res)
    f.write("{} {}\n".format(a[i],k[i]))
    for j in test[i]:
        f.write(str(j) + " ")
    f.write("\n")   
    f.write(str(res) + "\n")
f.close()
