//
//  방문길이.swift
//  Swift_Code
//
//  Created by InJe Choi on 2022/03/21.
//

/*
 set을 활용해 지나왔던 경로인지 확인한다
 지나왔던 경로의 시작점과 끝점을 구분하지 않고 경로 자체를 사용하면 안 되므로
 set에 양방향으로 경로를 추가해준다
 */

import Foundation

var visited = Set<[Int]>()
var answer = 0
var currentX = 0
var currentY = 0

func checker(_ y: Int, _ x: Int) {
    let nextX = currentX + x
    let nextY = currentY + y
    
    if -5 <= nextX && nextX <= 5 && -5 <= nextY && nextY <= 5 {
        currentY = nextY
        currentX = nextX
        
        if !visited.contains([currentX - x, currentY - y, currentX, currentY]) {
            answer += 1
            visited.insert([currentX - x, currentY - y, currentX, currentY])
            visited.insert([currentX, currentY, currentX - x, currentY - y])
        }
    }
}

func solution(_ dirs: String) -> Int {
    dirs.forEach {
        if $0 == "U" {
            checker(-1, 0)
        } else if $0 == "D" {
            checker(1, 0)
        } else if $0 == "L" {
            checker(0, -1)
        } else {
            checker(0, 1)
        }
    }
    
    return answer
}

// print(solution("LRLRL"))
