conn = {}
check = []

def DFS(x):
    check.append(x)

    if x in conn:
        for i in conn[x]:
            if i not in check:
                DFS(i)

if __name__ == '__main__':
    n = int(input())
    line = int(input())

    for i in range(n):
        conn[i+1] = set()

    for i in range(line):
        p, k = map(int, input().split())

        conn[p].add(k)
        conn[k].add(p)

    DFS(1)
    print(len(check) - 1)
