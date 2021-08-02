import sys
input = sys.stdin.readline

n = int(input())

temp = []
for i in range(n):
    a, b = map(int, input().split())
    temp.append([a, b])

temp = sorted(temp)

for a, b in temp:
    print(str(a) + " " + str(b))