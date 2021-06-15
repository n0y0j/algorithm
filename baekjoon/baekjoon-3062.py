n = int(input())

for i in range(n):
    item = input()
    temp = item[::-1]

    res = int(item) + int(temp)
    temp2 = str(res)
    
    for i in range(len(temp2) // 2):
        if temp2[i] != temp2[len(temp2) - i - 1]:
            print('NO')
            break
    else:
        print('YES')

    
    

