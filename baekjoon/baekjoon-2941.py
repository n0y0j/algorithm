n = input()

cnt = 0
i = 0

while i < len(n):
    if i + 1 < len(n) and ( n[i] == 'l' or n[i] == 'n' ) and n[i+1] == 'j':
        i += 2
        cnt += 1
    elif i + 1 < len(n) and n[i] == 'd' and n[i+1: i+3] == 'z=':
        i += 3
        cnt += 1
    elif i + 1 < len(n) and ( n[i] == 'c' or n[i] == 'd' or n[i] == 's' or n[i] == 'z' ) and ( n[i+1] == '=' or n[i+1] == '-' ):
        i += 2
        cnt += 1
    else:
        i += 1
        cnt += 1
    
print(cnt)