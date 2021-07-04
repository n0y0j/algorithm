from collections import deque

while True:
    w, h = map(int, input().split())

    if w == 0 and h == 0:
        break
    
    board = [ list(map(int, input().split())) for _ in range(h) ]

    dx = [-1, 0, 1, 0, -1, 1, -1, 1]
    dy = [0, -1, 0, 1, -1, -1, 1, 1]
    cnt = 0

    for i in range(h):
        Q = deque()
        for j in range(w):
            if board[i][j] == 1:
                board[i][j] = 0
                Q.append((i, j))
                cnt += 1

                while Q:
                    tmp = Q.popleft()

                    for k in range(len(dx)):
                        x = tmp[0] + dx[k]
                        y = tmp[1] + dy[k]

                        if 0 <= x < h and 0 <= y < w and board[x][y] == 1:
                            board[x][y] = 0
                            Q.append((x, y))

    print(cnt)