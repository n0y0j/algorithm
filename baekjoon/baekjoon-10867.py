n = int(input())
temp = list(map(int, input().split()))
res = sorted(set(temp))

for i in res:
    print(i, end=' ')