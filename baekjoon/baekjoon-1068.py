tree = {}

def remove(x):
    for i in tree[x]:
        remove(i)

    del tree[x]

def root_check(x):
    for i in tree:
        if x in tree[i]:
            tree[i].remove(x)

if __name__ == '__main__':
    n = int(input())
    temp = list(map(int, input().split()))
    remove_idx = int(input())
    cnt = 0

    for i in range(n):
        tree[i] = []

    for i in range(n):
        if temp[i] == -1:
            continue
        else:
            tree[temp[i]].append(i)

    remove(remove_idx)
    root_check(remove_idx)

    for i in range(n):
        if i in tree and len(tree[i]) < 1:
            cnt += 1
    
    print(cnt)

