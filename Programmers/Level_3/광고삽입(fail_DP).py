'''
https://programmers.co.kr/learn/courses/30/lessons/72414?language=python3

'''

def solution(play_time, adv_time, logs):
    answer = ''
    time_second = []
    idx = 0
    duplicated_part = []
    sum_part = []
    start_time = []
    end_time = [-1]
    d_idx = 0
    max_idx = 0
    
    if play_time == adv_time:
        return "00:00:00"
    
    def str_to_second():
        nonlocal time_second, play_time, adv_time
        pt = play_time.split(":")
        play_time = int(pt[0]) * 3600 + int(pt[1]) * 60 + int(pt[2])
        at = adv_time.split(":")
        adv_time = int(at[0]) * 3600 + int(at[1]) * 60 + int(at[2])
        
        for log in logs:
            s, e = log.split("-")
            start, end = s.split(":"), e.split(":")
            s_second = int(start[0]) * 3600 + int(start[1]) * 60 + int(start[2])
            e_second = int(end[0]) * 3600 + int(end[1]) * 60 + int(end[2])
            time_second += [[s_second, e_second]]
    
    str_to_second()
    time_second.sort(key=lambda x: x[1])
    
    while idx < len(time_second)-1:
        duplicated_part += [[]]
        cnt = 0
        
        for i in range(idx + 1, len(time_second)):
            if time_second[idx][1] > time_second[i][0]:
                if end_time[-1] != time_second[idx][1]:
                    end_time += [time_second[idx][1]]
                    start_time += [time_second[idx][0]]
                    
                duplicated_part[d_idx] += [time_second[idx][1] - time_second[i][0]]
                cnt += 1
            else:
                break
        
        idx += cnt + 1
        d_idx += 1
    
    end_time = end_time[1:]
    print("start_time:", start_time)
    print("end_time:", end_time)
    
    for d in duplicated_part:
        sum_part += [sum(d)]
    print("sum_part:", sum_part)
    
    max_idx = sum_part.index(max(sum_part))
    print("max_idx:", max_idx)
    
    begin_time = end_time[max_idx] - adv_time
    if begin_time < 0:
        begin_time = start_time[max_idx]
    print("begin_time:", begin_time)
    
    hour, minute, second = begin_time // 3600, begin_time % 3600 // 60, begin_time % 3600 % 60
    answer = f'{"%02d" % hour}:{"%02d" % minute}:{"%02d" % second}'

    return answer

print(solution("02:03:55", 
              "00:14:15", 
              ["01:20:15-01:45:14", "00:40:31-01:00:00", "00:25:50-00:48:29", "01:30:59-01:53:29", "01:37:44-02:02:30"]))