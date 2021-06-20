n, k = map(int, input().split())
temp = []
res = 0

for i in range(n):
    temp.append(int(input()))

left = 1
right = max(temp)

while left <= right:
    mid = ( left + right ) // 2
    cnt = 0

    for i in temp:
        cnt += i // mid
    
    if cnt < k:
        right = mid - 1
    else:
        res = mid
        left = mid + 1

print(res)
