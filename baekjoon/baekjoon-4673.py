temp = [False] * 10001

def d(n):
    if n < 10:
        temp[n+n] = True
    else:
        temp_val = n
        res = temp_val

        while temp_val > 0:
            res += temp_val % 10
            temp_val = temp_val // 10

        if res <= 10000:
            temp[res] = True
  
for i in range(1, len(temp)):
    d(i)

for i in range(1, len(temp)):
    if not temp[i]:
        print(i)