tree = {}

def preorder(x):
    if x != '.':
        print(x, end='')

        if x in tree:
            preorder(tree[x][0])
            preorder(tree[x][1])

def inorder(x):
    if x != '.':
        if x in tree:
            inorder(tree[x][0])
        
        print(x, end='')

        if x in tree:
            inorder(tree[x][1])

def postorder(x):
    if x != '.':
        if x in tree:
            postorder(tree[x][0])
            postorder(tree[x][1])
            
        print(x, end='')


if __name__ == '__main__':
    n = int(input())
    temp = []

    for i in range(n):
        root, left, right = map(str, input().split())
        tree[root] = [left, right]

    preorder('A')
    print()
    inorder('A')
    print()
    postorder('A')
