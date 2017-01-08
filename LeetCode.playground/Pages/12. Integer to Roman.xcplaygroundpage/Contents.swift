//: [Previous](@previous)
//https://leetcode.com/problems/integer-to-roman/

import Foundation

class Solution {
    func intToRoman(_ num: Int) -> String {
        
        let I = ["","I","II","III","IV","V","VI","VII","VIII","IX"]
        let X = ["", "X","XX","XXX","XL","L","LX","LXX","LXXX","XC"]
        let C = ["", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"]
        let M = ["", "M", "MM", "MMM"]
        
        
        return M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[num%10];
    }
}

let testInt = 1301
Solution().intToRoman(testInt)


//: [Next](@next)
