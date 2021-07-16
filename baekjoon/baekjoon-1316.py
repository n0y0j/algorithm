def check(n):
    word = {}
    for i in range(len(n)):
        if n[i] not in word.keys():
            word[n[i]] = True

            if i > 0:
                word[n[i-1]] = False
        else:
            if not word[n[i]]:
                return False

    return True

if __name__ == '__main__':
    t = int(input())
    cnt = 0
    for i in range(t):
        if check(input()):
            cnt += 1
    
    print(cnt)