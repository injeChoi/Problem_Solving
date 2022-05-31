'''
https://www.acmicpc.net/problem/1182

조합을 만들어서 조합의 합이 S가 되는 개수를 찾는 문제 
'''

def solution():
    N, S = map(int, input().split())
    arr = list(map(int, input().split()))
    answer = 0
    
    def check_lst(lst):
        if lst and sum(lst) == S:
            return 1
        return 0
    
    def dfs(idx, lst):
        nonlocal answer
        
        if len(lst) == len(arr):
            if check_lst(lst):
                answer += 1
            return

        if check_lst(lst):
            answer += 1
        
        for i in range(idx, len(arr)):
            dfs(i+1, lst + [arr[i]])
            
    dfs(0, [])
    print(answer)
    
solution()