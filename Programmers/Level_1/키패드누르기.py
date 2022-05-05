'''
https://programmers.co.kr/learn/courses/30/lessons/67256

키패드 위치를 저장하는 딕셔너리 만들고
새로 눌러야 하는 번호의 위치가 1번 열에 있으면 
현재 좌, 우 손가락 위치 부터 새로 눌러야하는 번호의 위치까지의 맨해튼 거리를 구한 후
상황에 맞는 값 추가 
'''

def solution(numbers, hand):
    answer = ''
    hand = 'L' if hand == "left" else 'R'
    left_side = [1, 4, 7]
    right_side = [3, 6, 9]
    left, right = '*', '#'
    keypad = {1: (0, 0), 2: (0, 1), 3: (0, 2), 
              4: (1, 0), 5: (1, 1), 6: (1, 2),
              7: (2, 0), 8: (2, 1), 9: (2, 2),
              '*': (3, 0) ,0: (3, 1), '#': (3, 2)}
    
    def check_distance(num):
        ty, tx = keypad[number][0], keypad[number][1]
        ly, lx = keypad[left][0], keypad[left][1]
        ry, rx = keypad[right][0], keypad[right][1]
        left_distance = abs(ty - ly) + abs(tx - lx)
        right_distance = abs(ty - ry) + abs(tx - rx)
        
        if left_distance < right_distance:
            return 'L'
        elif right_distance < left_distance:
            return 'R'
        else:
            return hand

    for number in numbers:
        if number in left_side:
            answer += 'L'
            left = number
        elif number in right_side:
            answer += 'R'
            right = number
        else:
            result = check_distance(number)
            answer += result
            if result == 'L':
                left = number
            else:
                right = number
            
    return answer

print(solution([7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2], "left"))