n = int(input())
dis = list(map(int, input().split()))
price = list(map(int, input().split()))

res = price[0] * dis[0]
cost = price[0]
dist = 0

for i in range(1, n-1):
    if price[i] < cost:
        res += cost * dist
        dist = dis[i]
        cost = price[i]
    else:
        dist += dis[i]

    if i == n-2:
        res += cost * dist

print(res)