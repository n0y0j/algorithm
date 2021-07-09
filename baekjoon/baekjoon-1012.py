import sys
sys.setrecursionlimit(100000)

temp = [[]]
dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]

def dfs(x, y):
    temp[y][x] = 0

    for i in range(4):
        x1 = x + dx[i]
        y1 = y + dy[i]

        if 0 <= x1 < m and 0 <= y1 < n and temp[y1][x1] == 1:
            dfs(x1, y1)

    return


if __name__ == '__main__':
    t = int(input())

    for _ in range(t):
        m, n, k = map(int, input().split())
        temp = [ [0] * m for _ in range(n) ]

        for i in range(k):
            x, y = map(int, input().split())
            temp[y][x] = 1
        
        cnt = 0

        for i in range(n):
            for j in range(m):
                if temp[i][j] == 1:
                    dfs(j, i)
                    cnt += 1

        print(cnt)