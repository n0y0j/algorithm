n = input()

cnt_1 = n.count('1')
cnt_0 = n.count('0')
res = ''
for i in range(cnt_0 // 2):
    res += '0'

for i in range(cnt_1 // 2):
    res += '1'

print(res)