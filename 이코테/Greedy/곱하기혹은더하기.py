userInput = input()
cal = 0

for i in range(1, len(userInput)):
    if userInput[i-1] == '0' or userInput[i-1] == '1':
        cal += int(userInput[i])
    else:
        if i == 1:
            cal += int(userInput[i-1])
        cal *= int(userInput[i])

print(cal)