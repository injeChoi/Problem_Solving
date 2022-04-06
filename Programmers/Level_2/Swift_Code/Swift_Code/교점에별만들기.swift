//
//  교점에별만들기.swift
//  Swift_Code
//
//  Created by InJe Choi on 2022/04/05.
//

/*
 1. 두 직선의 교점 찾는 공식 활용
 2. 평행일 때, 교점이 무수히 많을 때 예외처리
 3. 교점들의 y의 최대, 최솟값과 x의 최대, 최솟값 구하기
 4. 이론적인 좌표와 컴퓨터적인 좌표 계산 후 별 찍기
 */

import Foundation

func solution(_ line: [[Int]]) -> [String] {
    var maxX = Int.min, maxY = Int.min, minX = Int.max, minY = Int.max
    var points = Set<[Int]>()
    var answer = [String]()
    
    func findCrossPoint(_ firstLine: [Int], _ secondLine: [Int]) {
        let a1 = firstLine[0], b1 = firstLine[1], c1 = firstLine[2]
        let a2 = secondLine[0], b2 = secondLine[1], c2 = secondLine[2]
        let divider = (a1 * b2 - b1 * a2)
        
        if divider == 0 {
            return
        }
        
        if (b1 * c2 - c1 * b2) % divider == 0 && (c1 * a2 - a1 * c2) % divider == 0 {
            let x = (b1 * c2 - c1 * b2) / divider
            let y = (c1 * a2 - a1 * c2) / divider
            points.insert([y, x])
            maxX = max(maxX, x)
            minX = min(minX, x)
            maxY = max(maxY, y)
            minY = min(minY, y)
        }
    }
    
    for i in 0..<line.count-1 {
        for j in i+1..<line.count {
            findCrossPoint(line[i], line[j])
        }
    }

    let width = maxX - minX + 1
    let height = maxY - minY + 1
    var graph = [[String]](repeating: Array(repeating: ".", count: width), count: height)
    
    points.forEach {
        graph[maxY - $0[0]][$0[1] - minX] = "*"
    }
    
    for g in graph {
        answer.append(g.reduce("", +))
    }
    
    return answer
}

// print(solution([[2, -1, 4], [-2, -1, 4], [0, -1, 1], [5, -8, -12], [5, 8, 12]]))
