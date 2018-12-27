//: [Previous](@previous)
//https://leetcode.com/problems/longest-common-prefix/

import Foundation

class Solution {
    func longestCommonPrefix(_ strs: [String]) -> String {
        if strs.count == 0 {
            return ""
        }
        
        let sortedStrs = strs.sorted()
        let result = sortedStrs.first?.commonPrefix(with: sortedStrs.last!)
        
        return result!
    }
}

let testStrs = ["abc","abcc","abc","abca","abca"]
Solution().longestCommonPrefix(testStrs)

//: [Next](@next)
