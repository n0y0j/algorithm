from math import sqrt

temp = [True] * ( 10000 + 1 )
temp[1] = False

for i in range(2, int(sqrt(len(temp))) + 1):
    if temp[i]:
        for j in range(2 * i, len(temp), i):
            temp[j] = False

t = int(input())

for i in range(t):
    n = int(input())
    res = []
    sub = 10000

    for j in range(2, n // 2 + 1):
        if temp[j]:
            val = n - j
            
            if temp[val] and sub > abs(val - j):
                sub = val - j
                res.clear()
                res.append(j)
                res.append(val)

    print('%d %d' %(min(res), max(res)))