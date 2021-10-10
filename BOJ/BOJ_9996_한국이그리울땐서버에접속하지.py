N = int(input())
pattern = input()
files = [input() for _ in range(N)]

idx = pattern.find('*')
front = pattern[:idx]
rear = pattern[idx+1:]

for string in files:
    flag = False
    if string.find(front) == 0 and string.rfind(rear) != -1:
        if string.find(front) + len(front)-1 < string.rfind(rear):
            if string.rfind(rear) == len(string) - len(rear):
                flag = True
    print('DA') if flag == True else print('NE')