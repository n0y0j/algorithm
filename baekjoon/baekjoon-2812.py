n, k = map(int, input().split())
temp = input()

res = []

for i in temp:
    while len(res) > 0 and res[-1] < i and k != 0:
        res.pop()
        k -= 1
        
    res.append(i)

if k != 0:
    res = res[:-k]

for i in res:
    print(i, end='')