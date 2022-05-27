//
//  여행경로.swift
//  Swift_Code
//
//  Created by InJe Choi on 2022/05/26.
//

/*
 https://programmers.co.kr/learn/courses/30/lessons/43164?language=swift
 
 출발지를 key, 목적지를 value로 취급하여 hash table을 만든다
 value를 내림차순으로 정렬한다 (pop으로 사전순으로 가장 앞에 있는 것 부터 방문)
 스택에 방문하는 노드를 넣고 그 노드에서 갈 수 있는 사전 순으로 가장 앞서는 도느 찾기
 만약 더 이상 갈 수 있는 노드가 없다면 방문한 노드를 답에 추가 
 */

import Foundation

func solution(_ tickets:[[String]]) -> [String] {
    var answer = [String]()
    var d = [String: [String]]()
    var stack = [String]()
    
    for ticket in tickets {
        d[ticket[0], default: [String]()].append(ticket[1])
    }
    
    for key in d.keys {
        d[key]?.sort(by: >)
    }
    
    stack.append("ICN")
    
    while !stack.isEmpty {
        let top = stack.last!
        
        if d[top, default: [String]()].count == 0 {
            answer.append(stack.removeLast())
        } else {
            stack.append(d[top]!.removeLast())
        }
    }
    
    return answer.reversed()
}

// print(solution([["ICN", "JFK"], ["HND", "IAD"], ["JFK", "HND"]]))
