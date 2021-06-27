temp = input()

res = []
cnt = 0

for i in range(len(temp)):
    if temp[i] == ')':
        res.pop()
        if temp[i-1] == '(':
            cnt += len(res)
        else:
            cnt += 1
    else:
        res.append(temp[i])

print(cnt)