from collections import defaultdict

def solution(s):
    answer = []
    data = []
    d = defaultdict(int)
    lst = s[1:-1].split("},")

    for i in range(len(lst)):
        lst[i] = lst[i][1:]
    lst[-1] = lst[-1][:-1]

    for item in lst:
        tmp = item.split(",")
        
        for num in tmp:
            d[int(num)] += 1

    for key in d.keys():
        data.append([d[key], key])
    
    data.sort(reverse=True)

    for item in data:
        answer.append(item[1])

    return answer