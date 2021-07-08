from math import sqrt

def isPrime(x):
    if x == 1:
        return False

    for i in range(2, int(sqrt(x)) + 1):
        if x % i == 0:
            return False
            
    return True

if __name__ == '__main__':
    n, m = map(int, input().split())

    for i in range(n, m + 1):
        if isPrime(i):
            print(i)