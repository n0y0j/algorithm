import sys
sys.setrecursionlimit(10 ** 9)

dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]

house_map = []
house_num = []

def check(x, y, cnt):
    house_num[cnt] += 1
    house_map[y][x] = 0

    for i in range(4):
        dx1 = x + dx[i]
        dy1 = y + dy[i]

        if 0 <= dx1 < n and 0 <= dy1 < n and house_map[dy1][dx1] == '1':
            check(dx1, dy1, cnt)

if __name__ == '__main__':
    n = int(input())
    cnt = 0

    for i in range(n):
        temp = input()
        temp_list = []
        for j in temp:
            temp_list.append(j)
        house_map.append(temp_list)

    for i in range(n):
        for j in range(n):
            if house_map[i][j] == '1':
                house_num.append(0)
                check(j, i, cnt)
                cnt += 1
    
    print(cnt)
    house_num.sort()
    for i in house_num:
        print(i)
                