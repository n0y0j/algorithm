n = int(input())

for i in range(n):
    k = int(input())
    temp = list(map(int, input().split()))

    min = float('inf')
    max = -1000000

    for j in temp:
        if min > j:
            min = j
        if max < j:
            max = j

    print('{0} {1}'.format(min, max))
