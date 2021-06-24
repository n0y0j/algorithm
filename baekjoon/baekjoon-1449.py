n, l = map(int, input().split())
temp = list(map(int, input().split()))
temp.sort()

cnt = 1
idx = temp[0]

for i in range(1, len(temp)):
    if temp[i] < idx + l:
        continue
    else:
        cnt += 1
        idx = temp[i]

print(cnt)