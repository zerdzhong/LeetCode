//: [Previous](@previous)
//https://leetcode.com/problems/longest-substring-without-repeating-characters/

import Foundation

class Solution {
    func lengthOfLongestSubstring(_ s: String) -> Int {
        var result = 0
        var charArray = [Character]()
        
        for character in s.characters {
            if charArray.contains(character) {
                charArray.removeSubrange(0...charArray.index(of: character)!)
            }

            charArray.append(character)
            result = max(result, charArray.count)
        }
        
        return result
    }
}

let testString = "dvdf"
Solution().lengthOfLongestSubstring(testString)

//: [Next](@next)
