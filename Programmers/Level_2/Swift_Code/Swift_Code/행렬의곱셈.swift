//
//  행렬의곱셈.swift
//  Swift_Code
//
//  Created by InJe Choi on 2022/03/11.
//
/// indices를 쓰면 안전하게 배열의 범위를 전체 조회할 수 있다
/// 배열 범위 밖을 참조해서 터질 일이 없음
/// answer 배열은 행렬의 곱셈 성질을 이용하여 미리 배열의 크기를 계산해서 초기화 

import Foundation

func solution(_ arr1:[[Int]], _ arr2:[[Int]]) -> [[Int]] {
    var answer = [[Int]](repeating: Array(repeating: 0, count: arr2[0].count), count: arr1.count)
    
    for m in arr1.indices {
        for n in arr2[0].indices {
            for k in arr1[0].indices {
                answer[m][n] += arr1[m][k] * arr2[k][n]
            }
        }
    }
    
    return answer
}

// print(solution([[1, 4], [3, 2], [4, 1]], [[3, 3], [3, 3]]))
