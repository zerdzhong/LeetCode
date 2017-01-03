//: [Previous](@previous)
//https://leetcode.com/problems/string-to-integer-atoi/

import Foundation

class Solution {
    func myAtoi(_ str: String) -> Int {
        var result :Int32 = 0, indicator: Int32 = 1
        var chars = str.trimmingCharacters(in: .whitespacesAndNewlines).utf8CString
        
        if chars[0] == 45  || chars[0] == 43{
            indicator = (chars[0] == 45) ? -1 : 1
            chars.removeFirst()
        }
        
        for char in chars {
            let num = Int32(char) - 48
            if num < 0 || num > 9 || num == -48{
                break
            }
            
            guard result < Int32.max / 10 || (result == Int32.max / 10 && num <= Int32.max % 10) else {
                if indicator == 1 {
                    return Int(Int32.max)
                } else {
                    return Int(Int32.min)
                }
            }
            
            result = result * 10 + num
        }
        
        return Int(result * indicator)
    }
}

let testString = "-2147483648"
Solution().myAtoi(testString)

//: [Next](@next)
