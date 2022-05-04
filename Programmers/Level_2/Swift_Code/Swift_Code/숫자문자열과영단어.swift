//
//  숫자문자열과영단어.swift
//  Swift_Code
//
//  Created by InJe Choi on 2022/05/03.
//

import Foundation

func solution(_ s: String) -> Int {
    let stringArr = s.map { String($0) }
    var strNum = "", tmp = ""
    let numbers = ["zero": "0", "one": "1", "two": "2", "three": "3", "four": "4",
                   "five": "5", "six": "6", "seven": "7", "eight": "8", "nine": "9"]
    
    for s in stringArr {
        if Int(s) != nil {
            strNum += s
        } else {
            tmp += s
        }
        
        if let num = numbers[tmp] {
            strNum += num
            tmp = ""
        }
    }

    return Int(strNum)!
}

// print(solution("2three45sixseven"))
