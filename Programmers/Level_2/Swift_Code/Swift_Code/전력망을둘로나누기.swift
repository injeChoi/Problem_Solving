//
//  전력망을둘로나누기.swift
//  Swift_Code
//
//  Created by InJe Choi on 2022/04/05.
//

/*
 DFS + 브루트포스(?)
 
 wires에서 원소 하나씩 빼서 인접리스트(2개의 전력망) 생성
 생성된 2개의 전력망에서 각각 몇개씩 인지 카운트
 (n - 먼저 구한거 = 먼저구한거 빼고 남은 개수, 고로 2번 dfs를 할 필요없음)
 전력망 2개의 개수 차이가 가장 적은거 찾아서 리턴
 */

import Foundation

func solution(_ n: Int, _ wires: [[Int]]) -> Int {
    var answer = Int(10e6)
    var graph = [[Int]](repeating: Array(), count: n + 1)
    var visited = [Bool](repeating: false, count: n + 1)
    var cnt = 1
    
    func dfs(_ i: Int) -> Int {
        visited[i] = true
        
        for node in graph[i] {
            if !visited[node] {
                cnt += 1
                _ = dfs(node)
            }
        }
        
        return cnt
    }
    
    for idx in 0..<wires.count {
        graph = [[Int]](repeating: Array(), count: n + 1)
        visited = [Bool](repeating: false, count: n + 1)
        var c1 = 0, c2 = 0
        
        for (i, wire) in wires.enumerated() {
            if i == idx {
                continue
            }
            graph[wire[0]].append(wire[1])
            graph[wire[1]].append(wire[0])
        }
        
        for i in 1...n {
            if !visited[i] {
                cnt = 1
                c1 = dfs(i)
                c2 = n - c1
                break
            }
        }

        answer = min(answer, abs(c1 - c2))
    }
    
    return answer
}

// print(solution(9, [[1,3],[2,3],[3,4],[4,5],[4,6],[4,7],[7,8],[7,9]]))
