//
//  피보나치수.swift
//  Swift_Code
//
//  Created by InJe Choi on 2022/03/11.
//
/// 파이썬과는 달리 Swift에선 큰 수에 취약하기 때문에 Int 범위를 넘어갈 때를 고려해야 한다.
/// 이를 대비해 memo 배열에 나머지 연산을 취하고 난 후의 값을 저장시켰다.
/// 그러면 memo 배열에 값이 없을 때만 새로 계산하면 되므로 중복 계산을 줄일 수 있다.
/// (한 번 bottom까지 (2 까지) 찍고 나면 memo[2] 부터 memo[n] 까지 값이 차오르게 된다.)

var memo = [Int](repeating: 0, count: 100001)

func fibo(_ n: Int) -> Int {
    if memo[n] != 0 {
        return memo[n]
    } else if n == 0 {
        return 0
    } else if n == 1 {
        return 1
    }
    
    memo[n] = (fibo(n - 1) + fibo(n - 2)) % 1234567
    return (fibo(n - 1) + fibo(n - 2)) % 1234567
}

func solution(_ n: Int) -> Int {
    fibo(n)
}

// print(solution(100))
