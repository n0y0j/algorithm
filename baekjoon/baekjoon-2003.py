n, m = map(int, input().split())
temp = list(map(int, input().split()))

lt = 0
rt = 1
tot = temp[0]
cnt = 0

while True:
    if tot < m:
        if rt < n:
            tot += temp[rt]
            rt += 1
        else:
            break
    elif tot == m:
        cnt += 1
        tot -= temp[lt]
        lt += 1
    else:
        tot -= temp[lt]
        lt += 1

print(cnt)