//
//  쿼드압축후개수세기.swift
//  Swift_Code
//
//  Created by InJe Choi on 2022/03/29.
//

/*
 분할 정복이 핵심
 
 특점 y, x 범위 내에서 숫자의 종류가 1개 이상이면 압축할 수 없으니 분할 시작
 처음 사각형 크기가 8x8 크기였고, y = 1, x = 1 이었다면 half = 8 / 2 = 4
 (1, 1) ~ (4, 4), (1, 5) ~ (4, 8), (5, 1) ~ (8, 4), (5, 5) ~ (8, 8) 로 분할
 각각의 범위 내에서 또 검사해서 분할할지 말지 결정
 분할했으면 조건을 충족하지 못하는 것이니 1 또는 0의 개수를 증가시키면 안 됨
*/

import Foundation

func solution(_ arr: [[Int]]) -> [Int] {
    var count = [0, 0]
    let n = arr.count
    
    func check(_ y: Int, _ x: Int, _ n: Int) {
        let target = arr[y][x]
        
        for i in y..<y+n {
            for j in x..<x+n {
                if target != arr[i][j] {
                    let half = n / 2
                    check(y, x, half)
                    check(y + half, x, half)
                    check(y, x + half, half)
                    check(y + half, x + half, half)
                    return
                }
            }
        }
        count[target] += 1
    }
    
    check(0, 0, n)
    return count
}

// print(solution([[1,1,0,0],[1,0,0,0],[1,0,0,1],[1,1,1,1]]))
