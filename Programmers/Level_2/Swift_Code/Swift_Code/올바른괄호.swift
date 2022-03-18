//
//  올바른괄호.swift
//  Swift_Code
//
//  Created by InJe Choi on 2022/03/18.
//

/*
 짝이 맞는지 체크하면 끝
 popLast는 pop할게 없으면 nil을 반환하기 때문에
 빈 배열일 때 pop을 시도하면 잘못된 괄호이니 false 리턴
 */

import Foundation

func solution(_ s: String) -> Bool {
    var st = [String]()

    if s.first == ")" {
        return false
    }
    
    for br in s {
        if br == "(" {
            st.append("(")
        } else {
            if st.popLast() == nil {
                return false
            }
        }
    }
    
    return st.isEmpty
}

// print(solution("()))"))
