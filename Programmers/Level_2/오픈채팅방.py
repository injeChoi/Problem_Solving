def solution(record):
    answer = []
    uid_name = {}

    for message in record:
        lst = message.split()
        if lst[0] != "Leave":
            uid_name[lst[1]] = lst[2]

    for message in record:
        lst = message.split()
        if lst[0] == "Enter":
            answer.append(uid_name[lst[1]] + "님이 들어왔습니다.")
        elif lst[0] == "Leave":
            answer.append(uid_name[lst[1]] + "님이 나갔습니다.")

    return answer
