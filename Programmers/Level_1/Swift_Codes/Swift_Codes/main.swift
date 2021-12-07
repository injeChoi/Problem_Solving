import Foundation

func solution(_ sentence:String, _ keyword:String, _ skips:[Int]) -> String {
    
    var answer = ""
    var sum = 0

    for (idx, range) in skips.enumerated() {
        
        // keyword 요소 하나씩 추출
        var k: Character
        if idx >= keyword.count {
            k = keyword[keyword.index(keyword.startIndex, offsetBy: idx - keyword.count)]
        } else {
            k = keyword[keyword.index(keyword.startIndex, offsetBy: idx)]
        }
        print(k)
        
        // skips가 0 이면 k만 answer에 붙임
        if range == 0 {
            answer += String(k)
            continue
        }
        
        // skips가 0이 아니면,
        // sentence에서 부분 문자열이 될 index 범위 추출
        let lowerBound = sentence.index(sentence.startIndex, offsetBy: sum)
        var upperBound: String.Index
        
        // 범위가 sentence 길이 넘지 않을 때 까지만 처리
        if sum + range < sentence.count {
            upperBound = sentence.index(sentence.startIndex, offsetBy: sum + range - 1)
            //sum += range
        } else {
            upperBound = sentence.index(before: sentence.endIndex)
        }
        
        // sentence에서 부분 문자열 추출
        let sub = sentence[lowerBound...upperBound]
        
        // 부분 문자열에서 keyword랑 같은게 있는거 처리
        for s in sub {
            if s == k {
                answer += String(s)
                sum += 1
                break
            }
            answer += String(s)
            sum += 1
            if sum >= sentence.count {
                break
            }
        }
        answer += String(k)
    }

    if sum < sentence.count {
        answer += sentence[sentence.index(sentence.startIndex, offsetBy: sum)...]
    }
    
    return answer
}

let a = solution("abcde fghi", "axyz", [3, 9, 0, 1])
print("answer: \(a)")
