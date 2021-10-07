def solution(s):
    if len(s) == 1:
        return 1
        
    answer = 10e9
    sep = len(s) // 2
    tmp = [[] for _ in range(sep)]
    result = [[] for _ in range(sep)]
    compress = []

    while sep > 0:
        idx = 0
        lst = []
        for i in range(sep, len(s)+sep, sep):
            lst.append(s[idx:i])
            idx += sep
        sep -= 1

        jump = 0
        while jump < len(lst):
            dist = 1
            if jump + 1 >= len(lst):
                tmp[sep].append([dist, lst[jump]])
                break
            for i in range(jump+1, len(lst)):
                if lst[jump] == lst[i]:
                    dist += 1
                if lst[jump] != lst[i] or i == len(lst)-1:
                    tmp[sep].append([dist, lst[jump]])
                    jump += dist
                    break

    for i, row in enumerate(tmp):
        for j in range(len(row)):
            d = ''.join(map(str, row[j]))
            if d[0] == '1' and d[1].isalpha():
                d = d[1:]
            result[i].append(d)
                
    for row in result:
        d = ''.join(row)
        compress.append(d)
        
    for string in compress:
        answer = min(answer, len(string))

    return answer

solution('xxxxxxxxxxyyy')