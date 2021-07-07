n, k = map(int, input().split())

temp = []
cnt = 0

for _ in range(n):
    temp.append(int(input()))

temp.sort(reverse=True)

for i in temp:
    tmp = k // i

    if tmp != 0:
        k =  k % ( i * tmp )
        cnt += tmp

print(cnt)