n = int(input())

def hanoi(n, from_p, to_p, aux_p):
    if n == 1:
        print(str(from_p) + " " + str(to_p))
        return
    
    hanoi(n-1, from_p, aux_p, to_p)
    print(str(from_p) + " " + str(to_p))
    hanoi(n-1, aux_p, to_p, from_p)

print(2**n - 1)
hanoi(n, 1, 3, 2)