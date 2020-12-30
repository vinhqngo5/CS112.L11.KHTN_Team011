import math
def ToiGian(a,b):
    ucln = math.gcd(int(a),int(b))
    return a/ucln,b/ucln
    
def SoSanh(a, b, c, d):
    if (a * d <= b * c):
        return 1
    else:
        return 0
a = int(input())
b = int(input())
c = int(input())
d = int(input())

i = 0
flag = 0
while (SoSanh(a, b, c, d)):
    i+=1
    a,b = ToiGian(a+1,b+1)
    if (a/b) == (c/d):
        flag = 1
        break
if flag == 0:
    print(0)
else:
    print(i)