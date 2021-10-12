T = int(input())

while T:
    T -= 1
    S = input().split()
    animal = []
    while True:
        s = input().split()
        if s[0] == 'what':
            for a in animal:
                while True:
                    if a in S:
                        idx = S.index(a)
                        del S[idx]
                    else:
                        break
            print(' '.join(S))
            break
        animal.append(s[2])