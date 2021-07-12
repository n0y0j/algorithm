n = int(input())
m = int(input())
s = input()
cnt = 0

idx = 1
pattern = 0

while idx < m - 1:
    if s[idx-1] == 'I' and s[idx] == 'O' and s[idx+1] == 'I':
        pattern += 1

        if pattern == n:
            pattern -= 1
            cnt += 1
        idx += 1
    else:
        pattern = 0
    
    idx += 1

print(cnt)