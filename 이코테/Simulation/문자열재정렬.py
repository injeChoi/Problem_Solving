userInput = list(input())
result = []
total = 0

for i in userInput:
    if i.isalpha():
        result.append(i)
    else:
        total += int(i)

result.sort()
if total > 0: result.append(str(total))
print(''.join(result))
