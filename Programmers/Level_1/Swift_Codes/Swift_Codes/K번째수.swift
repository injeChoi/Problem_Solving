//
//  K번째수.swift
//  Swift_Codes
//
//  Created by InJe Choi on 2021/09/13.
//

import Foundation

func solution(_ array:[Int], _ commands:[[Int]]) -> [Int] {
    var answer = [Int]()
    
    for arr in commands {
        let from = arr[0]-1, to = arr[1]-1, idx = arr[2]-1
        var tmpArr = Array(array[from...to])
        tmpArr.sort()
        answer.append(tmpArr[idx])
    }
    return answer
}
