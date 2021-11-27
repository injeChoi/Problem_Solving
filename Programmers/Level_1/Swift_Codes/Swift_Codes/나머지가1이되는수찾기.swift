//
//  나머지가1이되는수찾기.swift
//  Swift_Codes
//
//  Created by InJe Choi on 2021/11/27.
//

import Foundation

func solution(_ n:Int) -> Int {
    
    for x in stride(from: 1, to: 1000000, by: 1) {
        if n % x == 1 {
            return x
        }
    }
    return 0
}
