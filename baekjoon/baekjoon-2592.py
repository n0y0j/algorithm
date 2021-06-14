count = 0
most = -1

temp = []
temp2 = set()

for i in range(10):
    temp.append(int(input()))
    temp2.add(temp[i])
    count += temp[i]

for i in temp2:
    if temp.count(most) < temp.count(i):
        most = i

print(int(count / 10))
print(most)