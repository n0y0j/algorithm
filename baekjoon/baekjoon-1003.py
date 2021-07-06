n = int(input())

for i in range(n):
    num = int(input())

    fibo = {}

    fibo[0] = [1, 0]
    fibo[1] = [0, 1]

    for i in range(2, num + 1):
        zero = fibo[i-1][0] + fibo[i-2][0]
        one = fibo[i-1][1] + fibo[i-2][1]

        fibo[i] = [zero, one]

    print('%d %d' %(fibo[num][0], fibo[num][1]))