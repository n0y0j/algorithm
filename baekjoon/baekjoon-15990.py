n = int(input())

dp = []
dp.append([0, 0, 0])
dp.append([1, 0, 0])
dp.append([0, 1, 0])
dp.append([1, 1, 1])

mod = 1000000009

for i in range(4, 100001):
    one = ( dp[i-1][1] + dp[i-1][2] ) % mod
    two = ( dp[i-2][0] + dp[i-2][2] ) % mod
    three = ( dp[i-3][0] + dp[i-3][1] ) % mod

    dp.append([one, two, three])

for _ in range(n):
    num = int(input())

    print(sum(dp[num]) % mod)