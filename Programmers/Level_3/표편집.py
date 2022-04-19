'''
https://programmers.co.kr/learn/courses/30/lessons/81303

배열로 풀다가 시간초과가 발생한 문제
최악의 경우 100만 * 100만이 될 수 있음을 간과했다

탐색을 할 때, N의 범위를 전체 탐색하지 않고 
링크드 리스트를 활용해 딱 원하는 만큼만 탐색해야 시간초과가 안 난다
(딕셔너리를 활용해 쉽게 링크드 리스트를 구현할 수 있다)

restore 부분에서 로직을 잘못 생각해서 4개의 테스트케이스에서 런타임에러가 났다
런타임 에러가 난 이유는 노드를 복원할 때 null 값 처리가 부족했기 때문이다
prev = 복원되려는 노드의 이전 노드, next = 복원되려는 노드의 다음 노드라 할 때,
복원되려는 노드의 prev 또는 next값에 null이 있다면 복원하는 로직이 약간 변경된다

가장 마지막에 삭제되어 현재 노드의 이전 또는 다음 포인터를 null로 만든 것이 스택의 top에 있기 때문에
그 녀석을 복원한다는 것은 복원되려는 노드가 무조건 현재 노드의 이전 또는 이후에 있음이 보장된다
근데 복원되려는 노드의 다음 노드가 null이란건 복원되려는 노드가 현재 노드보다 다음 노드였다는 뜻이고
반대로 이전 노드가 null이란건 복원되려는 노드가 현재 노드보다 이전 노드였다는 뜻이 된다
고로 복원되려는 노드의 포인터 중 null 값이 있다면 특성에 맞춰 
복원되려는 노드의 next가 null이면 prev가 복원되려는 노드를 가리키고,
prev가 null이면 next가 현재 노드를 가리키면 된다

만약 복원하려는 노드의 포인터 중 null 값이 없다면 단순히 연결 작업해주면 된다 
'''

def solution(n, k, cmd):
    linked_list = dict()
    st = []
    answer = ["O"] * n
    
    def make_linkedlist():
        for i in range(n):
            if i == 0:
                linked_list[i] = [-1, 1]
            elif i == n-1:
                linked_list[i] = [i-1, -1]
            else:
                linked_list[i] = [i-1, i+1]
                
    def up(num):
        nonlocal k
        for _ in range(num):
            k = linked_list[k][0]
    
    def down(num):
        nonlocal k
        for _ in range(num):
            k = linked_list[k][1]
    
    def cut():
        nonlocal st, k
        st += [[k, linked_list[k]]]
        
        if linked_list[k][0] == -1:
            linked_list[linked_list[k][1]][0] = -1
            k = linked_list[k][1]
        if linked_list[k][1] == -1:
            linked_list[linked_list[k][0]][1] = -1
            k = linked_list[k][0]
        elif linked_list[k][0] != -1 and linked_list[k][1] != -1:
            linked_list[linked_list[k][0]][1] = linked_list[k][1]
            linked_list[linked_list[k][1]][0] = linked_list[k][0]
            k = linked_list[k][1]
    
    def restore():
        idx, info = st.pop()
        
        if info[0] == -1:
            linked_list[info[1]][0] = idx
        elif info[1] == -1:
            linked_list[info[0]][1] = idx
        else:
            linked_list[info[0]][1] = idx
            linked_list[info[1]][0] = idx
                
    make_linkedlist()
    
    for c in cmd:
        if len(c) > 1:
            direction, num = c.split()
            if direction == "D":
                down(int(num))
            else:
                up(int(num))
        else:
            if c == "C":
                cut()
            else:
                restore()
                
    for item in st:
        answer[item[0]] = "X"
    
    return ''.join(answer)

print(solution(5, 4, ["C", "C", "C", "C", "Z"]))