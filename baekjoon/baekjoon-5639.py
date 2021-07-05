import sys
sys.setrecursionlimit(10 ** 9)

tree = []

def post(start, end):
    if start > end:
        return

    div = end + 1

    for i in range(start + 1, end + 1):
        if tree[start] < tree[i]:
            div = i
            break
    
    post(start + 1, div - 1)
    post(div, end)
    print(tree[start])

if __name__ == '__main__':
    for i in range(10000):
        try:
            tree.append(int(input()))
        except:
            break

    post(0, len(tree) - 1)