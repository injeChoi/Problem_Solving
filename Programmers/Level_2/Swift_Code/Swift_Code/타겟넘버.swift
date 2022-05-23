//
//  타겟넘버.swift
//  Swift_Code
//
//  Created by InJe Choi on 2022/05/23.
//

/*
 dfs를 돌리는데 for문을 사용해서 오류가 남
 정답 코드와는 달리 dfs 함수 안에 if문 아래에서 else문 대신
 for문으로 cnt ~ numbers.count 범위로 iterating을 하면서
 index 값을 1씩 증가시키면서 numbers 배열에서 해당 index의 값을 추가, 감소 시키는 로직으로 했었다
 이러면 문제가, index는 numbers.count랑 동일한데 cal 값을 증가 또는 감소 시킨 횟수는 1회 밖에 안 될 수도 있다
 ex)
 for i in cnt..<numbers.count {
    dfs(i + 1, cal + numbers[i])
    dfs(i + 1, cal - numbers[i])
 }
 이러면 depth가 1인 상태에서 for문이 numbers.count 만큼 돌아서
 cnt == numbers.count가 되지만 cal의 값이 numbers[0] +- numbers[1] 밖에 안 되는 경우가 발생한다는 것
 */

import Foundation

func solution(_ numbers: [Int], _ target: Int) -> Int {
    var answer = 0
    
    func dfs(_ cnt: Int, _ cal: Int) {
        if cnt == numbers.count {
            if cal == target {
                answer += 1
            }
            return
        } else {
            dfs(cnt + 1, cal + numbers[cnt])
            dfs(cnt + 1, cal - numbers[cnt])
        }
    }
    
    dfs(0, 0)
    return answer
}

print(solution([4, 1, 2, 1], 4))
