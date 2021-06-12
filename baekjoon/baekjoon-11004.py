n, k = map(int, input().split())

temp = input().split()
list = []

for i in temp:
    list.append(int(i))

list.sort()
print(list[k-1])