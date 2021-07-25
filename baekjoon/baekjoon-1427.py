n = input()
temp_list = []

for i in n:
    temp_list.append(i)

temp_list.sort(reverse=True)

for i in temp_list:
    print(i, end='')