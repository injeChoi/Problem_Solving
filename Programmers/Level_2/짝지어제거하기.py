def solution(s):
    st = []

    for i in range(len(s)):
        if len(st) == 0:
            st.append(s[i])
            continue
        
        if st[-1] == s[i]:
            st.pop()
        else:
            st.append(s[i])
            
    return 1 if len(st) == 0 else 0

solution('cdcd')