n, m = map(int, input().split())
temp = list(map(int, input().split()))
res = 0

left = 1
right = max(temp)

while left <= right:
    mid = ( left + right ) // 2
    res_temp = 0

    for i in temp:
        sub = i - mid
        if sub > 0:
            res_temp += i - mid

    if res_temp < m:
        right = mid - 1
    else:
        res = mid
        left = mid + 1

print(res)
