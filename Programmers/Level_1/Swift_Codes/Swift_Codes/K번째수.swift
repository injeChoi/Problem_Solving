//
//  main.swift
//  Swift_Codes
//
//  Created by InJe Choi on 2021/09/11.
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

solution([1, 5, 2, 6, 3, 7, 4], [[2, 5, 3], [4, 4, 1], [1, 7, 3]])
