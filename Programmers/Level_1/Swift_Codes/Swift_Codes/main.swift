//
//  main.swift
//  Swift_Codes
//
//  Created by InJe Choi on 2021/09/12.
//

import Foundation

func solution(_ clothes:[[String]]) -> Int {
    
    var answer = 0
    var d = [String : Int]()
    
    clothes.forEach {
        d[$0[1], default: 0] += 1
    }
    
    answer += d.count
    
    
    
    print(answer)
    return answer
}
