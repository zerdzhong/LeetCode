//: [Previous](@previous)
// https://leetcode.com/problems/longest-palindromic-substring/

import Foundation

class Solution {
    func longestPalindrome(_ s: String) -> String {
        
        if s.characters.count < 3 {
            return s
        }
        
        let chars = s.utf8CString
        var resultRange: Range<Int> = 0..<1
        
        for (index, _) in s.characters.enumerated() {
            let r1 = findLongest(chars, left: index, right: index)
            let r2 = findLongest(chars, left: index, right: index + 1)
            
            if r1.count > resultRange.count {
                resultRange = r1
            }
            
            if r2.count > resultRange.count {
                resultRange = r2
            }
        }
        
        let leftIndex = s.index(s.startIndex, offsetBy: resultRange.lowerBound)
        let rightIndex = s.index(s.startIndex, offsetBy: resultRange.upperBound)
        
        return s.substring(with: leftIndex..<rightIndex)
    }
    
    private func findLongest(_ chars: ContiguousArray<CChar>, left: Int, right: Int) -> Range<Int> {
        
        var left = left, right = right
        
        let length = chars.count
        while left >= 0 && right < length {
            
            if chars[left] != chars[right] {
                break
            }
            
            left -= 1
            right += 1
        }
        
        
        return left+1..<right
    }
}

let testString = "cbbd"
Solution().longestPalindrome(testString)

//: [Next](@next)
