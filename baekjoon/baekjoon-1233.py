s1, s2, s3 = map(int, input().split())

temp = [0] * (s1 + s2 + s3 + 3)
max = -1
index = -1

for i in range(1, s1 + 1):
    for j in range(1, s2 + 1):
        for k in range(1, s3 + 1):
            temp[i + j + k] += 1

for i in range(len(temp)):
    if temp[i] > max:
        max = temp[i]
        index = i

print(index)