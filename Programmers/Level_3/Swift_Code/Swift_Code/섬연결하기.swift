//
//  섬연결하기.swift
//  Swift_Code
//
//  Created by InJe Choi on 2022/04/06.
//

/*
 https://programmers.co.kr/learn/courses/30/lessons/42861

 최단경로를 구하는데 특정 정점에서의 최소비용이 아니라 그래프의 최소비용이니까 최소신장트리
 => 크루스칼 or 프림

 크루스칼 코드 로직: Union Find + 사이클 판별

 각 원소마다 부모를 알려주는 부모 배열 선언 (처음엔 자기자신이 부모)
 부모 찾기 로직 (경로압축 필수), 부모 합치기 로직 (부모를 비교해서 더 상위인 그룹한테 합침)

 사이클 판별을 위해 각 경로를 조사하면서
 출발 정점과 도착 정점의 부모를 비교해서 다른 부모를 가지고 있으면
 서로 연결되도 사이클이 안 생기는 놈들이니 합치기 실행 (Union)
 합치면 그 간선의 가중치를 총 비용에 추가
 */

import Foundation

func solution(_ n: Int, _ costs: [[Int]]) -> Int {
    var answer = 0
    var parent = Array(stride(from: 0, through: n, by: 1))
    let costs = costs.sorted { $0[2] < $1[2] }
    
    func findParent(_ x: Int) -> Int {
        if parent[x] != x {
            parent[x] = findParent(parent[x])
        }
        return parent[x]
    }
    
    func unionParent(_ a: Int, _ b: Int) {
        let a = findParent(a)
        let b = findParent(b)
        
        if a < b {
            parent[b] = a
        } else {
            parent[a] = b
        }
    }
    
    for cost in costs {
        let a = cost[0], b = cost[1], c = cost[2]
        
        if findParent(a) != findParent(b) {
            unionParent(a, b)
            answer += c
        }
    }
    
    return answer
}

// print(solution(4, [[0,1,1],[0,2,2],[1,2,5],[1,3,1],[2,3,8]]))
