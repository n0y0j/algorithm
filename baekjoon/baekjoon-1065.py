n = int(input())

cnt = 99

if n < 100:
    cnt = n
else:
    for i in range(100, n + 1):
        temp = str(i)
        
        if int(temp[2]) - int(temp[1]) == int(temp[1]) - int(temp[0]):
            cnt += 1

print(cnt)