import sys
input = sys.stdin.readline
n = int(input())
a = list(map(int, input().split()))
m = int(input())
b = list(map(int, input().split()))

a.sort()

for i in b:
    l = 0
    r = len(a) - 1

    while l <= r:
        m = ( r + l ) // 2

        if a[m] == i:
            print('1')
            break

        if i < a[m]:
            r = m - 1
        else:
            l = m + 1
    else:
        print('0')