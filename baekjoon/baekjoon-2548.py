n = int(input())

temp = list(map(int, input().split()))

# 중앙값 구하기
temp.sort()
print(temp[int((n-1)/2)])