n = int(input())
A = list(map(int, input().split()))
mi, pivot, res, l, ans_l, ans_r = 0, 0, 0, -1, -1, -1
for i in range(n):
    pivot += A[i]
    if (pivot < mi):
        mi = pivot
        l = i
    if (pivot - mi > res):
        res = pivot - mi
        ans_l = l
        ans_r = i
print(ans_l + 2, ans_r + 1, res)
