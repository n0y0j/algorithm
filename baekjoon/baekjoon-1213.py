n = input()

alpha = [0] * 26
odd = 0

odd_alpha = ''
even_alpha = ''

for i in n:
    alpha[ord(i) - 65] += 1

for i in range(len(alpha)):
    if alpha[i] == 0:
        continue

    if alpha[i] % 2 == 1:
        odd += 1
        odd_alpha += chr(i + 65)

    even_alpha += chr(i + 65) * (alpha[i] // 2)
    
if odd > 1:
    print("I'm Sorry Hansoo")
else:
    print(even_alpha + odd_alpha + even_alpha[::-1])
        
