temp = input()
val = input()

cnt = 0
idx = 0

while idx <= len(temp) - len(val):
    if temp[idx: idx + len(val)] == val:
        cnt += 1
        idx += len(val)
    else:
        idx += 1

print(cnt)