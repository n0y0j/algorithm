temp = []
count = 0

for i in range(5):
    temp.append(int(input()))
    count += temp[i]

temp.sort()
print(int(count / 5))
print(temp[2])