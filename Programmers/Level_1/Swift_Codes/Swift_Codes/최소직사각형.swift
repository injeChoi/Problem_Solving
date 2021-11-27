//
//  최소직사각형.swift
//  Swift_Codes
//
//  Created by InJe Choi on 2021/11/27.
//

import Foundation

func solution(_ sizes:[[Int]]) -> Int {
    
    var width = [Int]()
    var height = [Int]()
    
    for item in sizes {
        if item[0] < item[1] {
            width.append(item[1])
            height.append(item[0])
        } else {
            width.append(item[0])
            height.append(item[1])
        }
    }
    
    width.sort(by: >)
    height.sort(by: >)
    
    print(width.first! * height.first!)
    return width.first! * height.first!
}
