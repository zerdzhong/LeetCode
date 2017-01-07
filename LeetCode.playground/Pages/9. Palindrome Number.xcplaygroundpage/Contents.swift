//: [Previous](@previous)
//https://leetcode.com/problems/palindrome-number/

import Foundation

class Solution {
    func isPalindrome(_ x: Int) -> Bool {
        if x < 0 || (x != 0 && x % 10 == 0) {
            return false
        }
        
        var reverse = 0, origin = x
        
        while origin > reverse {
            reverse = reverse * 10 + origin % 10
            origin = origin / 10
        }
        
        return (reverse == origin || origin == reverse / 10)
    }
}

Solution().isPalindrome(121)

//: [Next](@next)
