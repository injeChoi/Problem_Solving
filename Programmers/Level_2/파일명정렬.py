def solution(files):
    answer = []

    for item in files:
        head, num, tail = '', '', ''
        flag = False
        i = 0

        while i < len(item):
            if item[i].isdigit():
                num += item[i]
                flag = True
            elif not flag:
                head += item[i]
            else:
                tail = item[i:]
                break

            i += 1
        
        answer.append([head, num, tail])

    answer.sort(key=lambda x : (x[0].upper(), int(x[1])))
    answer = [''.join(item) for item in answer]
    return answer


solution(["foo.a-s.d1.zip"])