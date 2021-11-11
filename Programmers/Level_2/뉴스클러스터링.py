from copy import deepcopy

def solution(str1, str2):
    str1 = str1.upper()
    str2 = str2.upper()
    lst1 = []
    lst2 = []
    cnt = 0

    for i in range(len(str1)-1):
        if 'A' <= str1[i] <= 'Z' or 'a' <= str1[i] <= 'z':
            if 'A' <= str1[i+1] <= 'Z' or 'a' <= str1[i+1] <= 'z':
                lst1.append(str1[i]+str1[i+1])

    for i in range(len(str2)-1):
        if 'A' <= str2[i] <= 'Z' or 'a' <= str2[i] <= 'z':
            if 'A' <= str2[i+1] <= 'Z' or 'a' <= str2[i+1] <= 'z':
                lst2.append(str2[i]+str2[i+1])

    if len(lst2) == 0 and len(lst1) == 0:
        return 65536

    tmp = deepcopy(lst2)

    for item in lst1:
        if item in tmp:
            del tmp[tmp.index(item)]
            cnt += 1

    for item in lst1:
        if lst1.count(item) > lst2.count(item):
            for i in range(lst1.count(item) - lst2.count(item)):
                lst2.append(item)

    return int(cnt / len(lst2) * 65536)
