X = input()
count = 0 
flag = False

while True:
    if len(X) != 1:
        X = str(sum(list(map(int, X))))
        count += 1
        
    if len(X) == 1:
        if int(X) % 3 == 0:
            flag = True
        break

if flag:
    print(count, "YES", sep='\n')
else:
    print(count, "NO", sep='\n')
