def pseudo(temp, left, right):
    while left < right:
        if temp[left] != temp[right]:
            return False
        else:
            left += 1
            right -= 1
    return True

def pal(temp, left, right):
    while left < right:
        if temp[left] != temp[right]:
            res1 = pseudo(temp, left + 1, right)
            res2 = pseudo(temp, left, right - 1)

            if res1 or res2:
                return 1
            else:
                return 2
        else:
            left += 1
            right -= 1

    return 0
 
n = int(input())

for i in range(n):
    temp = input()
    temp_len = len(temp) - 1
    res = pal(temp, 0, temp_len)
    print(res)