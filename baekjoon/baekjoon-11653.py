n = int(input())

temp = []

while n > 1:
    for i in range(2, n+1):
        if n % i == 0:
            temp.append(i)
            n = n // i
            break

temp.sort()

for i in temp:
    print(i)