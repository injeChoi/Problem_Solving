from math import ceil

N = int(input())
nums = list(map(int, input().split()))
ops = list(map(int, input().split()))
MAX = -1000000001
MIN = 1000000001

def dfs(result, cnt):
    global MAX, MIN

    if cnt == N-1:
        MIN = min(MIN, result)
        MAX = max(MAX, result)
        return

    for i in range(4):  
        if ops[i] != 0: # 특정 연산자를 사용하고 다음 연산으로 넘어가기
            ops[i] -= 1
            
            if i == 0: 
                dfs(result + nums[cnt+1], cnt+1)
            elif i == 1: 
                dfs(result - nums[cnt+1], cnt+1)
            elif i == 2: 
                dfs(result * nums[cnt+1], cnt+1)
            elif i == 3: 
                if result / nums[cnt+1] < 0:
                    dfs(ceil(result / nums[cnt+1]), cnt+1)
                else:
                    dfs(result // nums[cnt+1], cnt+1)
                
            ops[i] += 1 # 특정 연산자 복구하고 다음 단계로 넘어가기, 그래야 다음 dfs에서 그 연산자 사용 가능 

dfs(nums[0], 0)
print(MAX, MIN, sep='\n')