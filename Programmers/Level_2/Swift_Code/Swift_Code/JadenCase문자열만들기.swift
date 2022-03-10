//
//  JadenCase문자열만들기.swift
//  Swift_Code
//
//  Created by InJe Choi on 2022/03/10.
//
//  split 함수는 [Substring]을 반환하기 때문에
//  map을 활용하여 [String]으로 만들어줌
//  문자열의 첫 글자만 대문자로 만들어주는 capitalized라는 Instance Property가 존재
//  하지만 첫 글자가 문자가 아닐 경우 문자에 해당하는 것을 찾아서 대문자로 만듦
//  고로, 숫자로 시작하는 경우는 예외처리 

import Foundation

func solution(_ s: String) -> String {
    let stringArray = s.split(separator: " ",
                              omittingEmptySubsequences: false).map {
        String($0).capitalized
    }
    var answer = [String]()

    stringArray.forEach {
        if $0.count == 0 {
            answer.append("")
        } else if $0[$0.startIndex].isNumber {
            answer.append($0.lowercased())
        } else {
            answer.append($0)
        }
    }
    
    return answer.joined(separator: " ")
}

// print(solution("qa  q "))
