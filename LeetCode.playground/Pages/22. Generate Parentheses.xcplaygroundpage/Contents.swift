//: [Previous](@previous)
//https://leetcode.com/problems/generate-parentheses/

import Foundation

class Solution {
    func generateParenthesis(_ n: Int) -> [String] {
        var parenthesis = [String]()
        
        generate(parArr: &parenthesis, str: "", left: n, right: n)
        
        return parenthesis
    }
    
    func generate(parArr: inout [String], str: String, left: Int, right: Int) -> Void {
        if left == 0 && right == 0 {
            parArr.append(str)
            return
        }
        
        if left > 0 {
            generate(parArr: &parArr, str: str + "(", left: left - 1, right: right)
        }
        
        if right > left {
            generate(parArr: &parArr, str: str + ")", left: left, right: right - 1)
        }
    }
}

Solution().generateParenthesis(2)

//: [Next](@next)
