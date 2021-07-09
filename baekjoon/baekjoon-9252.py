import sys
sys.setrecursionlimit(100000)

s1 = input()
s2 = input()

dy = [ [0] * ( len(s1) + 1 ) for _ in range(len(s2) + 1) ]

x_list = [1, 0]
y_list = [0, 1]

res = []
cnt = 0

for i in range(1, len(s2) + 1):
    for j in range(1, len(s1) + 1):
        if s1[j - 1] == s2[i - 1]:
            dy[i][j] = dy[i-1][j-1] + 1
        else:
            dy[i][j] = max(dy[i][j-1], dy[i-1][j])

cnt = dy[len(s2)][len(s1)]

def dfs(x, y, cnt):
    if x == 0 or y == 0:
        return 

    if dy[x][y] == cnt:
        for i in range(2):
            x1 = x_list[i]
            y1 = y_list[i]

            if dy[x - x1][y - y1] == cnt:
                dfs(x - x1, y - y1, cnt)
                return 
        
        cnt -= 1
        res.append(s2[x-1])
        dfs(x-1, y-1, cnt)

dfs(len(s2), len(s1), cnt)
print(cnt)

if cnt != 0:
    for i in range(len(res) - 1, -1, -1):
        print(res[i], end='')