l = "aeiou"

while True:
    s = input()
    chk,chk2 = 0,0

    if s == "end": 
        break

    for i in s:
        if i in l:
            chk2 = 1

    for i in range(1,len(s)):
        if s[i] == s[i-1] and s[i] not in 'eo': 
            chk=1

    for i in range(len(s)-2):
        if s[i] in l and s[i+1] in l and s[i+2] in l: 
            chk = 1
        elif s[i] not in l and s[i+1] not in l and s[i+2] not in l: 
            chk = 1

    if chk == 1 or chk2 == 0: 
        print("<" + s + "> is not acceptable." )
    else: 
        print("<" + s + "> is acceptable." )