S = input()
lst = ['pi', 'ka', 'chu']

for l in lst:
    S = S.replace(l, ' ')

for i in range(len(S)):
    if 'a' <= S[i] <= 'z':
        print('NO')
        break
else: print('YES')