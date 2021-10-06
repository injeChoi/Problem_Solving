from collections import deque

lst = input().split()
ucpc = deque(['U', 'C', 'P', 'C'])

for string in lst:
    for i in range(len(string)):
        if len(ucpc) == 0:
            break
        if string[i] == ucpc[0]:
            ucpc.popleft()

if ucpc:
    print("I hate UCPC")
else:
    print("I love UCPC")
