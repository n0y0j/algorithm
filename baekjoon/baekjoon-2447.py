def e_star(n):
    matrix = []

    for i in range(3 * len(n)):
        if i // len(n) == 1:
            matrix.append(n[i % len(n)] + ' ' * len(n) + n[i % len(n)])
        else:
            matrix.append(n[i % len(n)] * 3)
    return matrix

star = ['***', '* *', '***']
n = int(input())
e = 0

while n != 3:
    n = n // 3
    e += 1

for _ in range(e):
    star = e_star(star)
for i in star:
    print(i)