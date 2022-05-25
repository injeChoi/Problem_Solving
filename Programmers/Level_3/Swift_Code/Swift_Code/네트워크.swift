//
//  네트워크.swift
//  Swift_Code
//
//  Created by InJe Choi on 2022/05/25.
//

/*
 https://programmers.co.kr/learn/courses/30/lessons/43162
 
 인접리스트 생성 후 dfs로 이어진 노드를 모두 방문하면서 방문처리
 방문처리 안 된 노드가 있다면 해당 노드를 기점으로 다시 dfs 처리하면서 답 1 증가 
 */

import Foundation

func solution(_ n:Int, _ computers:[[Int]]) -> Int {
    var answer = 0
    var graph = [[Int]](repeating: [Int](), count: computers.count)
    var visited = [Bool](repeating: false, count: computers.count)
    
    func makeGraph() {
        for i in 0..<computers.count {
            for j in 0..<computers[0].count {
                if computers[i][j] == 1 && i != j {
                    graph[i].append(j)
                }
            }
        }
    }
    
    func dfs(_ idx: Int) {
        if visited[idx] == true {
            return
        }
        
        visited[idx] = true
        
        for e in graph[idx] {
            dfs(e)
        }
    }
    
    makeGraph()
    
    for i in 0..<computers.count {
        if visited[i] == false {
            answer += 1
            dfs(i)
        }
    }
    
    return answer
}

// print(solution(3, [[1, 1, 0], [1, 1, 1], [0, 1, 1]]))
