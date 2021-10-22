N, K = map(int, input().split())
num = input()
st = []
k = K

for i in range(len(num)):
    n = int(num[i])
    if len(st) == 0 or k == 0:
        st.append(n)
        continue
    if st[-1] >= n:
        st.append(n)
    else:
        while k and len(st) > 0 and st[-1] < n:
            k -= 1
            st.pop()
        st.append(n)
    
print(''.join(map(str, st[0:N-K])))