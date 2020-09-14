n = int(input())

temp = input()
person_data = temp.split(" ")
person = list(map(int, person_data))
person.sort()

wait = 0
sum = 0

for i in range(n):
  wait += int(person[i])
  sum += wait

print(sum)