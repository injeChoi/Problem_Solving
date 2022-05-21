//
//  오픈채팅방.swift
//  Swift_Code
//
//  Created by InJe Choi on 2022/05/21.
//

import Foundation

func solution(_ record: [String]) -> [String] {
    var answer = [String]()
    var nameInfo = [String: String]()
    var enterLeaveInfo = [[String]]()
    
    func parsing(_ str: String) {
        let tmp = str.split(separator: " ").map { String($0) }
        var info = "", uid = "", name = ""
        
        if tmp.count == 2 {
            info = tmp[0]
            uid = tmp[1]
        } else {
            info = tmp[0]
            uid = tmp[1]
            name = tmp[2]
        }
        
        if info == "Enter" {
            enterLeaveInfo.append([uid, "님이 들어왔습니다."])
            nameInfo[uid, default: ""] = name
        } else if info == "Leave" {
            enterLeaveInfo.append([uid, "님이 나갔습니다."])
        } else {
            nameInfo[uid, default: ""] = name
        }
    }
    
    for r in record {
        parsing(r)
    }
    
    for info in enterLeaveInfo {
        answer.append(nameInfo[info[0], default: ""] + info[1])
    }
    
    return answer
}
