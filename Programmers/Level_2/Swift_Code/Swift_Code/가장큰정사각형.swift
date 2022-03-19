//
//  가장큰정사각형.swift
//  Swift_Code
//
//  Created by InJe Choi on 2022/03/18.
//

/*
 해설: https://github.com/injeChoi/Problem_Solving/blob/master/Programmers/Level_2/가장큰정사각형.py
 */

import Foundation

func solution(_ board: [[Int]]) -> Int {
    var answer = 0
    var board = board
    
    board.forEach {
        if $0.contains(1) {
            answer = 1
        }
    }
    
    for row in 1..<board.count {
        for col in 1..<board[0].count {
            if board[row][col] == 1 {
                board[row][col] = min(board[row-1][col-1], board[row-1][col], board[row][col-1]) + 1
                answer = max(answer, board[row][col])
            }
        }
    }
    
    return answer * answer
}

// print(solution([[0,1,1,1],[1,1,1,1],[1,1,1,1],[0,0,1,0]]))
