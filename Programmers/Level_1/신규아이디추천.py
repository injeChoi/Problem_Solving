'''
https://programmers.co.kr/learn/courses/30/lessons/72410

구현력을 보는 문제, python이 아니었다면 시간을 좀 잡아먹을 듯 하다 
'''

def solution(new_id):

    def to_lowercase():
        nonlocal new_id
        new_id = new_id.lower()
    
    def remove_others():
        nonlocal new_id
        tmp = ""
        
        for c in new_id:
            if c.isalnum() or c in ["-", "_", "."]:
                tmp += c

        new_id = tmp
        
    def remove_duplicate():
        nonlocal new_id
        
        while new_id.find("..") != -1:
            new_id = new_id.replace("..", ".")
                
    def remove_start_end():
        nonlocal new_id
        
        if new_id[0] == ".":
            if len(new_id) == 1:
                new_id = ""
            else:
                new_id = new_id[1:]
                
        if len(new_id) > 0 and new_id[-1] == ".":
            new_id = new_id[:-1]
        
    def check_empty():
        nonlocal new_id
        
        if new_id == "":
            new_id = "a"
    
    def check_length():
        nonlocal new_id
        
        if len(new_id) > 15:
            new_id = new_id[:15]
            
        remove_start_end()
    
    def extend_length():
        nonlocal new_id
        
        if len(new_id) < 3:
            new_id += new_id[-1] * (3 - len(new_id))
    
    to_lowercase()
    remove_others()
    remove_duplicate()
    remove_start_end()
    check_empty()
    check_length()
    extend_length()
    
    return new_id

print(solution("...!@BaT#*..y.abcdefghijklm"))
