//
//  다리를지나는트럭.swift
//  Swift_Code
//
//  Created by InJe Choi on 2022/04/16.
//

/*
 https://programmers.co.kr/learn/courses/30/lessons/42583

 큐 = 다리
 weight = 다리가 버틸 수 있는 총 무게

 큐에서 pop되는 원소의 개수를 카운트하는 것이 중점

 1.
 큐가 꽉차면 원소를 하나 pop 하면서 answer를 1 증가시킨다.
 pop되는 순간 빈 자리가 하나 생기는 것이므로 새로운 loop이 진행되는 것이 아니라
 다음 트럭을 큐에 넣을 수 있는지 체크한다.

 2.
 큐가 가득 차지 않았는데 새로 추가하려는 트럭의 무게 + 기존 무게 > weight인 경우가 발생하면 큐에 0을 추가한다.
 (트럭이 추가되지 않는 것을 의미 + 초가 흐름을 의미)

 3.
 큐가 가득차지 않고 새로 추가하려는 트럭의 무게 + 기존 무게 <= weight인 경우엔 큐에 새로운 트럭을 추가하면서
 큐의 총 무게를 증가시킨다.

 1 ~ 3 반복하다가 반복문을 탈출하게 되면 큐에 남아있는 원소의 개수를 답에 추가한다.
 반복문은 큐에 트럭을 추가하는 로직일 뿐이므로 최종적으로 다리(큐)에 남아있는 트럭들이 다리를 다 건너는 시간도 계산해야 한다.
 */

import Foundation

struct Queue<T> {
    var enqueue = [T]()
    var dequeue = [T]()
    
    var isEmpty: Bool {
        return enqueue.isEmpty && dequeue.isEmpty
    }
    
    var count: Int {
        return enqueue.count + dequeue.count
    }
    
    mutating func push(_ element: T) {
        enqueue.append(element)
    }
    
    mutating func pop() -> T? {
        if dequeue.isEmpty {
            dequeue = enqueue.reversed()
            enqueue.removeAll()
        }
        return dequeue.popLast()
    }
}

func solution(_ bridge_length: Int, _ weight: Int, _ truck_weights: [Int]) -> Int {
    var answer = 0
    var total = 0
    var queue = Queue<Int>()
    var idx = 0
    queue.enqueue = [Int](repeating: 0, count: bridge_length)

    while idx < truck_weights.count {
        if queue.count == bridge_length {
            answer += 1
            total -= queue.pop()!
        }
        if total + truck_weights[idx] > weight {
            queue.push(0)
        } else {
            queue.push(truck_weights[idx])
            total += truck_weights[idx]
            idx += 1
        }
    }
    
    answer += queue.count
    return answer
}
