n = int(input())

temp = []
for i in range(n):
    s, e = map(int, input().split())
    temp.append([s, e])

temp.sort(key = lambda x : (x[1], x[0]))

end_t = 0
cnt = 0

for s, e in temp:
    if s >= end_t:
        end_t = e
        cnt += 1
        
print(cnt)