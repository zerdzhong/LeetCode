//: [Previous](@previous)
//https://leetcode.com/problems/roman-to-integer/

import Foundation

class Solution {
    func romanToInt(_ s: String) -> Int {
        var result = 0, preNum = 0
        let romanMap: [Character: Int] = ["I": 1,"V": 5,"X": 10,"L": 50,"C": 100,"D": 500,"M": 1000]
        
        for char in s.characters {
            guard let num = romanMap[char] else {
                break
            }
            
            if num == preNum * 5 || num == preNum * 10{
                result -= 2 * preNum
            }
            
            preNum = num
            result += num
        }
        
        return result
    }
}

let testRoman = "MCMXCVI"
Solution().romanToInt(testRoman)

//: [Next](@next)
