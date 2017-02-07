//: [Previous](@previous)
//https://leetcode.com/problems/valid-parentheses/

import Foundation

class Solution {
    func isValid(_ s: String) -> Bool {
        
        var charStack = [Character]()
        
        for char in s.characters {
            if char==")", charStack.last=="(" {
                charStack.removeLast()
            } else if char=="]", charStack.last=="[" {
                charStack.removeLast()
            } else if char=="}", charStack.last=="{" {
                charStack.removeLast()
            } else {
                charStack.append(char)
            }
        }
        
        return (charStack.count == 0)
    }
}

Solution().isValid("()[]{}")

//: [Next](@next)
