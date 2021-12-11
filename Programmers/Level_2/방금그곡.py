from math import ceil

def solution(m, musicinfos):
    answer = ["(None)", None]
    m = m.replace("C#", "c").replace("D#", "d").replace("F#", "f").replace("G#", "g").replace("A#", "a")

    for item in musicinfos:
        start, end, title, melody = item.split(',')
        start = start.split(':')
        end = end.split(':')
        duration = (int(end[0]) - int(start[0])) * 60 + (int(end[1]) - int(start[1]))
        melody = melody.replace("C#", "c").replace("D#", "d").replace("F#", "f").replace("G#", "g").replace("A#", "a")
        length = len(melody)

        melody *= ceil(duration / length)
        melody = melody[:duration]

        if m in melody:
            if answer[1] == None or duration > answer[1]:
                answer = [title, duration]

    return answer[0]


print(solution("CCB", ["03:00,03:10,FOO,CCB#CCB", "04:00,04:08,BAR,ABC"]))