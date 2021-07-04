from collections import deque

n, m = map(int, input().split())
dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]

maze = []

for i in range(n):
    temp = input()
    temp_list = []

    for j in temp:
        temp_list.append(int(j))

    maze.append(temp_list)

dis = [ [0] * m for _ in range(n) ]

Q = deque()
Q.append((0, 0))
maze[0][0] = 0
dis[0][0] = 1

while Q:
    tmp = Q.popleft()

    for i in range(4):
        x = tmp[0] + dx[i]
        y = tmp[1] + dy[i]

        if 0 <= x < n and 0 <= y < m and maze[x][y] == 1:
            maze[x][y] = 0
            dis[x][y] = dis[tmp[0]][tmp[1]] + 1
            Q.append((x, y))

print(dis[n-1][m-1])