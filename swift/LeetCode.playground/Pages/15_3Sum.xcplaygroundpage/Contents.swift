//: [Previous](@previous)
//https://leetcode.com/problems/3sum/

import Foundation

class Solution {
    func threeSum(_ nums: [Int]) -> [[Int]] {
        var result = [[Int]]()
        let sortedNums = nums.sorted()
        
        for i in 0..<sortedNums.count {
            if i > 0 && sortedNums[i] == sortedNums[i-1] {
                continue
            }
            
            let wantNum = 0 - sortedNums[i]
            var j = i + 1, k = sortedNums.count - 1
            
            while j < k {
                let sum = sortedNums[j] + sortedNums[k]
                if sum == wantNum {
                    result.append([sortedNums[i], sortedNums[j], sortedNums[k]])
                    
                    j += 1
                    k -= 1
                    
                    while j < k && sortedNums[j] == sortedNums[j-1] {
                        j += 1
                    }
                    
                    while j < k && sortedNums[k] == sortedNums[k+1] {
                        k -= 1
                    }
                    
                } else if sum > wantNum {
                    k -= 1
                } else {
                    j += 1
                }
            }
        }
        
        return result
    }
}

let testInts = [-2,0,0,2,2]
Solution().threeSum(testInts)

//: [Next](@next)
