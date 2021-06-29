n = int(input())
temp = input()
temp_list = []
s1 = []
alpha = [0] * n

for i in temp:
    if i >= 'A' and i <= 'Z':
        if alpha[ord(i) - 65] != 0:
            temp_list.append(alpha[ord(i) - 65])
        else:
            num = int(input())
            alpha[ord(i) - 65] = num
            temp_list.append(num)
    else:
        temp_list.append(i)

for i in temp_list:
    if type(i) is int:
        s1.append(i)
    else:
        a = s1.pop()
        b = s1.pop()

        if i == '+':
            s1.append(b + a)
        elif i == '-':
            s1.append(b - a)
        elif i == '*':
            s1.append(b * a)
        else:
            s1.append(b / a)

print('%0.2f' % s1[0])