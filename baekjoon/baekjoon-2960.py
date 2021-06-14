n, k = map(int, input().split())

temp = [0] * ( n + 1 )
cnt = 0
for i in range(2, n + 1):
    if temp[i] == 0 and cnt != k:

        for j in range(2, n + 1):
            if j % i == 0 and temp[j] != 1:
                temp[j] = 1
                cnt += 1

                if cnt == k:
                    print(j)
                    break