//
//  가장먼노드.swift
//  Swift_Code
//
//  Created by InJe Choi on 2022/03/23.
//

/*
 https://programmers.co.kr/learn/courses/30/lessons/49189
 
 Swift에는 큐가 없으니 큐 구현 연습
 (이 문제는 O(N)의 시간복잡도로 pop을 시켜줘도 되지만 바람직하진 않다)
 
 노드간 양방향 처리 후
 BFS로 가장 가까운 노드부터 depth를 줘가면서 탐색
 방문한 노드는 visited 처리
 */

import Foundation

struct Queue<T> {
    private var queue = [T?]()
    private var head = 0
    
    public var count: Int {
        return queue.count - head
    }
    
    public var isEmpty: Bool {
        return queue.count == head
    }
    
    public mutating func push(_ item: T) {
        queue.append(item)
    }
    
    public mutating func pop() -> T? {
        guard head < queue.count, let element = queue[head] else {
            return nil
        }
        
        queue[head] = nil
        head += 1
        
        if head > 50 {
            queue.removeFirst(head)
            head = 0
        }
        
        return element
    }
}

func bfs(_ graph: [[Int]], _ n: Int) -> Int? {
    var visited = [Int](repeating: 0, count: n + 1)
    var queue = Queue<[Int]>()
    visited[1] = 1
    
    for item in graph[1] {
        queue.push([item, 1])
    }
    
    while !queue.isEmpty {
        guard let info = queue.pop() else { return nil }
        let node = info[0]
        let depth = info[1]
        
        if visited[node] == 0 {
            visited[node] = depth
            for item in graph[node] {
                queue.push([item, depth + 1])
            }
        }
    }
    
    let maxNumber = visited.max()
    return visited.filter { $0 == maxNumber }.count
}

func solution(_ n: Int, _ edge: [[Int]]) -> Int {
    var graph = [[Int]](repeating: [Int](), count: n + 1)
    
    for path in edge {
        graph[path[0]].append(path[1])
        graph[path[1]].append(path[0])
    }
    
    guard let answer = bfs(graph, n) else { return -1 }
    
    return answer
}

// print(solution(6, [[3, 6], [4, 3], [3, 2], [1, 3], [1, 2], [2, 4], [5, 2]]))
