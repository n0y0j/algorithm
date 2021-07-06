n = int(input())
dp = [0, 1, 2, 4]

for i in range(4, 1000001):
    dp.append( (dp[i-3] + dp[i-2] + dp[i-1]) % 1000000009)

for i in range(n):
    num = int(input())
    print(dp[num])