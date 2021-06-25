n = int(input())
temp = []
alpha = [0] * 26
val = 9
sum = 0

for i in range(n):
    temp.append(input())

temp.sort(key=len, reverse=True)

for i in temp:
    key = len(i) - 1
    for j in i:
        alpha[ord(j) - 65] += 10 ** key
        key -= 1

alpha.sort(reverse=True)

for i in alpha:
    if i != 0:
        sum += i * val
        val -= 1

print(sum)
