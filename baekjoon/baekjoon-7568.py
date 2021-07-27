n = int(input())
temp = []

for _ in range(n):
    x, y = map(int, input().split())
    temp.append([x, y])

for i in temp:
    rank = 1
    for j in temp:
        if i[0] != j[0] and i[1] != j[1]:
            if i[0] < j[0] and i[1] < j[1]:
                rank += 1
    
    print(rank, end=" ")