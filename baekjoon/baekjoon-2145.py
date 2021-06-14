while True:
    n = int(input())

    if n == 0:
        break

    while n >= 10:

        temp0 = n
        temp1 = 0

        while temp0 > 0:
            temp1 += temp0 % 10
            temp0 //= 10
        
        n = temp1
    
    print(n)