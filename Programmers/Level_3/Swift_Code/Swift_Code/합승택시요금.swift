//
//  합승택시요금.swift
//  Swift_Code
//
//  Created by InJe Choi on 2022/04/08.
//

/*
 https://programmers.co.kr/learn/courses/30/lessons/72413

 전형적인 플로이드 워셜 알고리즘 문제
 모든 최소 경로를 구한 후
 s -> v, v -> A, v -> B 까지의 가중치를 합산해서 최솟값 찾으면 끝

 주의할 점은 플로이드 워셜 알고리즘의 시간복잡도가 O(N^3)이기 때문에
 V의 값이 1000 정도만 되도 시간 초과에 걸릴 수 있다

 하지만 이 문제에서 N의 최댓값이 200이기 때문에 위 알고리즘을 적용해도 된다
 */

import Foundation

func solution(_ n: Int, _ s: Int, _ a: Int, _ b: Int, _ fares: [[Int]]) -> Int {
    let INF = Int(1e9)
    var graph = [[Int]](repeating: [Int](repeating: INF, count: n + 1), count: n + 1)
    var answer = INF
    
    func makeGraph() {
        fares.forEach {
            graph[$0[0]][$0[1]] = $0[2]
            graph[$0[1]][$0[0]] = $0[2]
        }
    }
    
    func floydWarshall() {
        for i in 1...n {
            graph[i][i] = 0
        }
        
        for k in 1...n {
            for i in 1...n {
                for j in 1...n {
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j])
                }
            }
        }
    }
    
    makeGraph()
    floydWarshall()
    
    for v in 1...n {
        answer = min(answer, graph[s][v] + graph[v][a] + graph[v][b])
    }
    
    return answer
}
