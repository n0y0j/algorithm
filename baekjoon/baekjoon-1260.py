from collections import deque

n, m ,v = map(int, input().split())

temp = [[0] * (n + 1) for _ in range(n + 1)]
visit = [0] * (n + 1)

for i in range(m):
    a, b = map(int, input().split())
    temp[a][b] = 1
    temp[b][a] = 1

def dfs(v):
    visit[v] = 1
    print(v, end=' ')

    for i in range(1, n+1):
        if visit[i] == 0 and temp[v][i] == 1:
            dfs(i)

def bfs(v):
    q = deque()
    q.append(v)
    visit[v] = 0

    while q:
        v = q.popleft()
        print(v, end=' ')
        for i in range(1, n + 1):
            if visit[i] == 1 and temp[v][i] == 1:
                q.append(i)
                visit[i] = 0

dfs(v)
print()
bfs(v)