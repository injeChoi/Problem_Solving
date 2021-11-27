//
//  부족한금액계산하기.swift
//  Swift_Codes
//
//  Created by InJe Choi on 2021/11/27.
//

import Foundation

func solution(_ price:Int, _ money:Int, _ count:Int) -> Int{
    
    var sum = 0
    
    for i in 1...count {
        sum += price * i
    }
    
    if money > sum {
        return 0
    } else {
        return sum - money
    }

}
