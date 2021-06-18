card = [ i for i in range(1, 21)]

for _ in range(10):
    f, l = map(int, input().split())

    for j in range((l - f + 1) // 2):
        card[f - 1 + j], card[l - 1 - j] = card[l - 1 - j], card[f - 1 + j]

for i in card:
    print(i, end=' ')