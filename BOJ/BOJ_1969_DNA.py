N, M = map(int, input().split())
lst = list(input() for _ in range(N))
DNA = ''
cnt = 0

for x in range(M):
    alphabets = []
    for i in range(26):
        alphabets.append([0, i])
    for y in range(len(lst)):
        alphabets[ord(lst[y][x])-ord('A')][0] += 1
    alphabets.sort(key= lambda x: (-x[0], x[1]))
    DNA += chr(alphabets[0][1]+65)

for string in lst:
    for i in range(len(string)):
        if DNA[i] != string[i]:
            cnt += 1

print(DNA)
print(cnt)