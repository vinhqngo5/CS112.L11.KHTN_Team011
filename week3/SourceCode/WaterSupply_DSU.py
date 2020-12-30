# Initialize variables
n, m = map(int, input().split())
root_arr = [i for i in range(n)]
count = [1 for _ in range(n)]
res = []
final_ans = 1
mod = 1000000007
# Find root of the node u


def root(u):
    global root_arr
    v = u
    while (u != root_arr[u]):
        u = root_arr[u]
    root_arr[v] = u
    return u

# Merge 2 nodes u and v


def merge(u, v):
    
    global root_arr
    global count
 
    u = root(u)
    v = root(v)

    if (u != v):
        if (count[u] > count[v]):
            root_arr[v] = u
            count[u] += count[v]
        else:
            root_arr[u] = v
            count[v] += count[u]


# Takes input and merge Node


for i in range(m):
    a, b =  input().split()
    a = int(a) - 1
    b = int(b) - 1
    merge(a, b)


# Caculate answer
for i in range(n):
    if (i == root_arr[i]):
        res.append(count[i])

for i in range(len(res)):
    final_ans = (round(final_ans * res[i])) % mod

for i in range(len(res) - 2):
    final_ans = (round(final_ans * n)) % mod

print(len(res) - 1)
print(final_ans)
