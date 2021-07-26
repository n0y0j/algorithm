import sys
from collections import Counter

n = int(sys.stdin.readline())

temp = []

for _ in range(n):
    temp.append(int(sys.stdin.readline()))
temp.sort()

print(round(sum(temp)/n))
print(temp[n // 2])

cnt = Counter(temp).most_common()
if len(cnt) > 1 and cnt[0][1] == cnt[1][1]:
    print(cnt[1][0])
else:
    print(cnt[0][0])

print(max(temp) - min(temp))