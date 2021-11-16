import math
import os
import random
import re
import sys

#
# Complete the 'organizingContainers' function below.
#
# The function is expected to return a STRING.
# The function accepts 2D_INTEGER_ARRAY container as parameter.
#

# n번째 컨테이너가 보유해야하는 있는 공의 개수와 
# n타입의 공의 개수가 같아야 한다.
# ex) 0번째 컨테이너가 보유 중인 공의 개수 2개, 0 타입 공 1개 -> Impossible

def organizingContainers(container):
    # Write your code here
    row = []
    col = []
    
    #col
    for i in range(n):
        total = 0
        for j in range(n):
            total += container[j][i]
        col.append(total)
        
    #row
    for i in range(n):
        total = 0
        for j in range(n):
            total += container[i][j]
        row.append(total)
        
    col.sort()
    row.sort()
    
    for i in range(n):
        if col[i] != row[i]:
            return "Impossible"
    
    return "Possible"
        
        
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input().strip())

    for q_itr in range(q):
        n = int(input().strip())

        container = []

        for _ in range(n):
            container.append(list(map(int, input().rstrip().split())))

        result = organizingContainers(container)

        fptr.write(result + '\n')

    fptr.close()
