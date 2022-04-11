//
//  모두0으로만들기(BFS).swift
//  Swift_Code
//
//  Created by InJe Choi on 2022/04/08.
//

/*
 https://programmers.co.kr/learn/courses/30/lessons/76503?

 Bottom-Up Traverse 개념이 중요

 트리 구조 그래프에선 모든 노드가 root가 될 수 있긴 하지만 편의상 0번 정점을 root라고 하고
 root 부터 순차적으로 모든 leaf 까지의 경로를 찾아본다

 찾은 경로를 역순으로 돌면서, 부모는 자식의 가중치 만큼 증가시키면서
 bottom-up으로 root까지 연산을 하며 찾아갔을 떄 root가 0이 되면 성공
 
 Queue에 넣는 값의 형태는 (부모, 자식) 정점
 초기 값으로는 0번 정점으로 시작하기 위해 (-1, 0)을 넣고 시작
 */

import Foundation

struct Queue<T> {
    var enQueue = [T]()
    var deQueue = [T]()
    
    var isEmpty: Bool {
        enQueue.isEmpty && deQueue.isEmpty
    }
    
    var count: Int {
        enQueue.count + deQueue.count
    }
    
    mutating func push(_ value: T) {
        enQueue.append(value)
    }
    
    mutating func pop() -> T? {
        if deQueue.isEmpty {
            deQueue = enQueue.reversed()
            enQueue.removeAll()
        }
        return deQueue.popLast()
    }
}

func solution(_ a: [Int], _ edges: [[Int]]) -> Int64 {
    var vertex = a
    var graph = [[Int]](repeating: [Int](), count: a.count)
    var cnt = 0, answer = 0
    var reversedPath = [(Int, Int)]()
    
    func makeGraph() {
        for edge in edges {
            let s = edge[0], e = edge[1]
            graph[s] += [e]
            graph[e] += [s]
        }
    }
    
    func bfs() -> [(Int, Int)] {
        var queue = Queue<(Int, Int)>()
        var visited = [Bool](repeating: false, count: a.count)
        var paths = [(Int, Int)]()
        queue.push((-1, 0))
        visited[0] = true
        
        while !queue.isEmpty {
            if let path = queue.pop() {
                let s = path.0, e = path.1
                paths += [(s, e)]
                
                for child in graph[e] {
                    if !visited[child] {
                        visited[child] = true
                        queue.push((e, child))
                    }
                }
            }
        }
        
        return paths.reversed().dropLast()
    }
    
    makeGraph()
    reversedPath = bfs()
    
    for (parent, child) in reversedPath {
        cnt += abs(vertex[child])
        vertex[parent] += vertex[child]
    }
    
    answer = vertex[0] == 0 ? cnt : -1
    return Int64(answer)
}

// print(solution([-5,0,2,1,2], [[0,1],[3,4],[2,3],[0,3]]))
