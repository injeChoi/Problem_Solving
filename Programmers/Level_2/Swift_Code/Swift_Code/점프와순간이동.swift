//
//  점프와순간이동.swift
//  Swift_Code
//
//  Created by InJe Choi on 2022/03/31.
//

/*
 https://programmers.co.kr/learn/courses/30/lessons/12980?language=swift
 
 뒤에서부터 절반씩 줄여나가다가 (순간이동) 홀수일 때 -1 처리(배터리사용)
 */

import Foundation

func solution(_ n: Int) -> Int {
    var answer = 0, n = n
    
    while n > 0 {
        if n % 2 == 1 {
            answer += 1
            n -= 1
        }
        n /= 2
    }
    
    return answer
}

// print(solution(5000))
