//
//  괄호회전하기.swift
//  Swift_Code
//
//  Created by InJe Choi on 2022/04/19.
//

/*
 1. 배열 회전 구현: Array Slice 신경쓰기 
 2. 괄호 종류별로 짝 맞추기
 */

import Foundation

func solution(_ s: String) -> Int {
    if s.count % 2 == 1 {
        return 0
    }
    
    let arr = Array(s).map { String($0) }
    var answer = 0
    
    for i in 0..<arr.count {
        let tmp = Array(arr[i+1..<arr.count]) + Array(arr[0...i])
        var cnt = 0
        var st = [String]()
        
        for s in tmp {
            if ["(", "[", "{"].contains(s) {
                st += [s]
            } else {
                if let top = st.popLast() {
                    if (s == ")" && top == "(") || (s == "]" && top == "[") || (s == "}" && top == "{") {
                        cnt += 1
                    } else {
                        break
                    }
                } else {
                    break
                }
            }
        }
        if cnt == s.count / 2 {
            answer += 1
        }
    }
    
    return answer
}

// print(solution("}]()[{"))
