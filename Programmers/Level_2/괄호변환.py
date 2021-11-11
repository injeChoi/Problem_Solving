def correct(string):
    st = []
    for s in string:
        if s == '(':
            st.append(s)
        else:
            if len(st) != 0 and st[-1] == '(':
                st.pop()
            else:
                return False
    return True

def divide(p):
    O = C = 0
    for i, s in enumerate(p):
        if s == '(': O += 1
        else: C += 1
        if O == C:
            return p[:i+1], p[i+1:]

def solution(p):
    if len(p) == 0:
        return ''
    
    u, v = divide(p)

    if correct(u):
        return u + solution(v)
    
    else:
        blank = '('
        blank += solution(v)
        blank += ')'
        for s in u[1:-1]:
            if s == '(':
                blank += ')'
            else:
                blank += '('
        return blank