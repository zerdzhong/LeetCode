//: [Previous](@previous)
//https://leetcode.com/problems/4sum/

import Foundation

class Solution {
    func fourSum(_ nums: [Int], _ target: Int) -> [[Int]] {
        var result = [[Int]]()
        
        guard nums.count >= 4 else {
            return result
        }
        
        let sortedNums = nums.sorted()
        
        for i in 0..<sortedNums.count - 1 {
            
            if i > 0 && sortedNums[i] == sortedNums[i-1] {
                continue
            }
            
            for j in i+1..<sortedNums.count - 1 {
                
                if j != i+1 && sortedNums[j] == sortedNums[j-1] {
                    continue
                }
                
                let wantNum = target - sortedNums[i] - sortedNums[j]
                var k = j + 1, f = sortedNums.count - 1
                
                while k < f {
                    let sum = sortedNums[k] + sortedNums[f]
                    if sum == wantNum {
                        result.append([sortedNums[i], sortedNums[j], sortedNums[k], sortedNums[f]])
                        
                        k += 1
                        f -= 1
                        
                        while k < f && sortedNums[k] == sortedNums[k-1] {
                            k += 1
                        }
                        
                        while k < f && sortedNums[f] == sortedNums[f+1] {
                            f -= 1
                        }
                        
                    } else if sum > wantNum {
                        f -= 1
                    } else {
                        k += 1
                    }
                }
            }
        }
        
        return result
    }
}

let testNums = [-1,-5,-5,-3,2,5,0,4]
Solution().fourSum(testNums, -7)

//: [Next](@next)
