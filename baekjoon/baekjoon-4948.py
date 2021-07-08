from math import sqrt

temp = [True] * ( 123456 * 2 + 1 )
temp[1] = False

for i in range(2, int(sqrt(len(temp))) + 1):
    if temp[i]:
        for j in range(2 * i, len(temp), i):
            temp[j] = False
        
while True:
    n = int(input())
    cnt = 0

    if n == 0:
        break

    for i in range(n + 1, 2 * n + 1):
        if temp[i]:
            cnt += 1

    print(cnt)