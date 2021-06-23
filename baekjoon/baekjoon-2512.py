# 6

# 2 9 20 11 20 30

# 50
n = int(input())
temp = list(map(int, input().split()))
val = int(input())

left = 0
right = val
max2 = 0
tt = 0

while left <= right:
    mid = ( left + right ) // 2
    res = 0
    cnt = 0

    for i in temp:
        if i > mid:
            res += mid
        else:
            cnt += 1
            res += i
       
    if res > val:
        right = mid - 1
    else:
        if cnt == len(temp):
            tt = max(temp)
            break

        left = mid + 1

        if max2 <= res and tt < mid:
            max2 = res
            tt = mid

print(tt)