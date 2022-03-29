//
//  다단계칫솔판매.swift
//  Swift_Code
//
//  Created by InJe Choi on 2022/03/28.
//

/*
 https://programmers.co.kr/learn/courses/30/lessons/77486

 다단계에 끌어들인 사람 A, 끌어들여진 사람을 B라고 할 때
 A와 B의 관계를 설정 후 저장 (양방향이 아님)
 
 판매 금액을 확인한 후 자기 위에 누가 있는지 계속 체크해가면서
 줘야할 돈이 1원 미만이거나, 위에 사람이 없을 때 까지 수수료 때이는 로직 실행
 */

import Foundation

func solution(_ enroll:[String], _ referral:[String], _ seller:[String], _ amount:[Int]) -> [Int] {
    var relationship = [String: String]()
    var hierarchy = [String: Int]()
    var answer = [Int]()
    
    for (enr, ref) in zip(enroll, referral) {
        relationship[enr] = ref
    }
    
    func recu(_ person: String, _ money: Int) {
        let give = money / 10
        let take = money - give
        hierarchy[person, default: 0] += take
        
        if relationship[person] == "-" || give == 0 {
            return
        }

        recu(relationship[person, default: "-"], give)
    }
    
    for (person, m) in zip(seller, amount) {
        let money = m * 100
        recu(person, money)
    }
    
    for name in enroll {
        answer.append(hierarchy[name, default: 0])
    }
    
    return answer
}
