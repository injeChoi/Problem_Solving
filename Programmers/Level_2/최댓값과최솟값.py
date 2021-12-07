def solution(s):
    
    string_lst = s.split()
    numeric_lst = [int(num) for num in string_lst]
    numeric_lst.sort()

    return str(numeric_lst[0]) + ' ' + str(numeric_lst[-1])

