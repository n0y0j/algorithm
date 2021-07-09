n, k = map(int, input().split())

item = [[0, 0]]
dy = [[0] * ( k + 1 ) for _ in range(n + 1)]

for _ in range(n):
    item.append(list(map(int, input().split())))

for i in range(1, n + 1):
    for j in range(1, k + 1):

        if j >= item[i][0]:
            dy[i][j] = max(dy[i - 1][j], dy[i - 1][j - item[i][0]] + item[i][1] )
        else:
            dy[i][j] = dy[i - 1][j]
    
print(dy[n][k])