//: [Previous](@previous)
//https://leetcode.com/problems/letter-combinations-of-a-phone-number/

import Foundation

let digitDic : [Character: Array<String>] = ["2":["a", "b", "c"],
                                             "3":["d", "e", "f"],
                                             "4":["g", "h", "i"],
                                             "5":["j", "k", "l"],
                                             "6":["m", "n", "o"],
                                             "7":["p", "q", "r", "s"],
                                             "8":["t", "u", "v"],
                                             "9":["w", "x", "y", "z"]]

class Solution {
    func letterCombinations(_ digits: String) -> [String] {
        
        if digits.lengthOfBytes(using: .utf8) < 1 {
            return [String]()
        }
        
        var result = [String].init(arrayLiteral: "")
        
        for char in digits.characters {
            guard let letters = digitDic[char]  else {
                break
            }
            
            let tmpResult = result
            result.removeAll()
            
            for i in 0..<letters.count {
                for j in 0..<tmpResult.count {
                    result.append(tmpResult[j] + letters[i])
                }
            }
            
            print("\(result)")
            
        }
        
        return result
    }
}

Solution().letterCombinations("23")

//: [Next](@next)
