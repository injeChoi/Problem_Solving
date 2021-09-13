//
//  main.swift
//  Swift_Codes
//
//  Created by InJe Choi on 2021/09/12.
//

import Foundation

var nums = Array(readLine()!).split(separator: " ").map { Int(String($0))! }
var con = readLine()!.map { Int(String($0))! }
print(nums.filter{ $0 == 1 }.count)
print(con.filter{ $0 == 2 }.count)


