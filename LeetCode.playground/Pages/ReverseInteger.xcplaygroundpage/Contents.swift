//: [Previous](@previous)
// https://leetcode.com/problems/reverse-integer/
// TODO:overflow not handle yet

import Foundation

class Solution {
    func reverse(_ x: Int) -> Int {
        var originInt = x
        var result = 0
        
        while originInt != 0 {
            result = result * 10 + originInt % 10
            originInt /= 10
        }
        
        
        return result
    }
}

let testInt = 15342364699999999
Solution().reverse(testInt)

//: [Next](@next)
