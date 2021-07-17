import math

def check(x):
    for i in range(2, int(math.sqrt(x)) + 1):
        if x % i == 0:
            return False
    return True

if __name__ == '__main__':
    n = int(input())
    m = int(input())
    res = 0
    min = 0
    for i in range(n, m + 1):
        if i != 1 and check(i):
            res += i

            if min == 0:
                min = i
    
    if res == 0:
        print(-1)
    else:
        print(res)
        print(min)
