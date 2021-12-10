def solution(s):
    st = []

    for item in s:
        if len(st) == 0:
            if item == ')':
                return False
            else:
                st.append(item)
                continue
        
        if item == '(':
            st.append(item)
        else:
            st.pop()

    if len(st) == 0:
        return True
    else:
        return False
