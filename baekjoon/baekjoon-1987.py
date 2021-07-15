import sys

r, c = map(int, sys.stdin.readline().split())
alpha_map = [list(sys.stdin.readline().strip()) for _ in range(r)]
ch = [0] * 26

dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]

answer = 1

def dfs(x, y, ans):
    global answer
    answer = max(answer, ans)
    
    for i in range(4):
        dx1 = x + dx[i]
        dy1 = y + dy[i]

        if 0 <= dx1 < c and 0 <= dy1 < r and ch[ord(alpha_map[dy1][dx1]) - 65] == 0:
            ch[ord(alpha_map[dy1][dx1]) - 65] = 1
            dfs(dx1, dy1, ans + 1)
            ch[ord(alpha_map[dy1][dx1]) - 65] = 0

ch[ord(alpha_map[0][0]) - 65] = 1
dfs(0, 0, answer)
print(answer)