n = int(input())
dp = [-1, 0]

for i in range(2, n + 1):
    temp = dp[i-1] + 1

    if i % 2 == 0:
        temp = ( dp[i//2] + 1 if temp > dp[i//2] + 1 else temp )
    if i % 3 == 0:
        temp = ( dp[i//3] + 1 if temp > dp[i//3] + 1 else temp )
    
    dp.append(temp)

print(dp[n])