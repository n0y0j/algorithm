n = int(input())

for i in range(n):

    list = []
    temp = input()
    item = temp.split()

    for j in item:
        list.append(int(j))

    list.sort()
    print(list[7])