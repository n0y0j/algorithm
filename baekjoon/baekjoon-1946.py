import sys

n = int(sys.stdin.readline())

for i in range(n):
    p = int(sys.stdin.readline())

    temp = []
    for j in range(p):
        s, e = map(int, sys.stdin.readline().split())
        temp.append([s, e])

    temp.sort()

    i_max = 0
    cnt = 0
    for s, e in temp:
        if s == 1:
            i_max = e
            cnt += 1
        
        if i_max > e:
            i_max = e
            cnt += 1

    print(cnt)
    
