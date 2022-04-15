'''
https://programmers.co.kr/learn/courses/30/lessons/92341

주어진 조건이 많아서 구현할게 많은 문제
하지만 records 배열의 길이가 최대 1000밖에 안 돼서 시간 초과 걱정은 하지 않아도 됨
문자열 토크나이징과 주차장 이용시간을 구하는 로직만 꼼꼼히 하면 끝 
'''

from collections import defaultdict
from math import ceil

def solution(fees, records):
    answer = []
    info = defaultdict(list)
    calculated = dict()
    base_time, base_cost, extra_time, extra_cost = fees
    
    def time_to_minute(time):
        h, m = time.split(":")
        return int(h) * 60 + int(m)
    
    def seperate_car():
        for record in records:
            time, car, detail = record.split()
            time = time_to_minute(time)
            info[car] += [[time, detail]]
            
    def check_no_out():
        for key, value in info.items():
            if len(value) % 2 == 1:
                info[key] += [[23 * 60 + 59, "OUT"]]
                
    def calculate_cost():
        for key, values in info.items():
            total_time, total_cost = 0, 0
            
            for i in range(1, len(values), 2):
                total_time += values[i][0] - values[i-1][0]
            
            if total_time > base_time:
                total_time -= base_time
                total_cost += base_cost
                total_cost += ceil(total_time / extra_time) * extra_cost
            else:
                total_cost = base_cost
                
            calculated[key] = total_cost
                
    seperate_car()
    check_no_out()
    calculate_cost()
    car_num = sorted(calculated.keys())
    
    for num in car_num:
        answer += [calculated[num]]

    return answer

solution([180, 5000, 10, 600],
         ["05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", 
          "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"])