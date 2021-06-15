n = int(input())
res = -1

def find_dex(x):
    if x == 1:
        return False
    
    for i in range(2, x // 2 + 1):
        if x % i == 0:
            return False
    else:
        return True

def find_pal(x):
    temp = str(x)
    temp_size = len(temp) - 1
    for i in range(len(temp) // 2):
        if temp[i] != temp[temp_size - i]:
            return False
    else:
        return True


while res == -1:
    if find_pal(n):
        if find_dex(n):
            res = n
    n += 1

print(res)