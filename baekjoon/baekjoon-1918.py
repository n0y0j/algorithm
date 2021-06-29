temp = input()

s1 = []
res = ''

for i in temp:
    if i == '(':
        s1.append(i)
    elif i == ')':
        while s1[-1] != '(':
            res += s1.pop()
        s1.pop()
    elif i >= 'A' and i <= 'Z':
        res += i
    elif i == '*' or i == '/':
        if len(s1) > 0 and ( s1[-1] == '*' or s1[-1] == '/' ):
            res += s1.pop()
        s1.append(i)
    else:
        while len(s1) > 0:
            if s1[-1] == '(':
                break
            res += s1.pop()
        s1.append(i)

while len(s1) > 0:
    res += s1.pop()

print(res)