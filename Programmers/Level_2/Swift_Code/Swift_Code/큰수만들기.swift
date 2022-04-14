//
//  큰수만들기.swift
//  Swift_Code
//
//  Created by InJe Choi on 2022/04/13.
//

/*
 문자열을 배열처럼 subscript 가능하게 처리 후
 숫자를 하나씩 확인하면서 스택의 top 값 보다 크다면 해당 숫자를 top으로 치환 -> 자연스럽게 스택에 내림차순으로 정렬됨
 문자열 순회 후 k가 0이 아니라면 숫자를 충분히 제거하지 못했다는 뜻이니
 스택에 쌓여있는 내림차순으로 정렬된 값 중 작은 n개의 값 제거
 */

import Foundation

func solution(_ number: String, _ k: Int) -> String {
    var k = k
    let nums = Array(number).map { String($0) }
    var stack = [String]()

    for num in nums {
        while k > 0 {
            if !stack.isEmpty && stack.last! < num {
                stack.removeLast()
                k -= 1
            } else {
                break
            }
        }
        stack += [num]
    }
    
    stack.removeLast(k)
    return stack.joined()
}

// print(solution("654312", 1))
