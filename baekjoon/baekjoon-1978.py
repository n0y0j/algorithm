n = int(input())

item = list(map(int, input().split()))
cnt = 0

def find_dec(x):
    if x == 1:
        return False
        
    for i in range(2, x // 2 + 1):
        if x % i == 0:
            return False
    else:
        return True

for i in item:
    if find_dec(i):
        cnt += 1

print(cnt)