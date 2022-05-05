//
//  크레인인형뽑기.swift
//  Swift_Codes
//
//  Created by InJe Choi on 2022/05/04.
//

/*
 https://programmers.co.kr/learn/courses/30/lessons/64061
 
 기본적인 스택 문제 + 2차원 배열 탐색
 */

import Foundation

func solution(_ board: [[Int]], _ moves: [Int]) -> Int {
    var board = board
    var answer = 0
    var stack = [Int]()
    let N = board.count
    
    for move in moves {
        for i in 0..<N {
            if board[i][move-1] != 0 {
                if !stack.isEmpty && stack.last! == board[i][move-1] {
                    answer += 2
                    stack.removeLast()
                } else {
                    stack.append(board[i][move-1])
                }
                
                board[i][move-1] = 0
                break
            }
        }
    }
    
    return answer
}
