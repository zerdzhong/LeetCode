//: [Previous](@previous)
//https://leetcode.com/problems/3sum-closest/

import Foundation

class Solution {
    func threeSumClosest(_ nums: [Int], _ target: Int) -> Int {
        
        if nums.count < 3 {
            return 0
        }
        
        var result = nums[0] + nums[1] + nums[2]
        let sortedNums = nums.sorted()
        
        for i in 0..<sortedNums.count {
            if i > 0 && sortedNums[i] == sortedNums[i-1] {
                continue
            }
            
            var j = i + 1, k = sortedNums.count - 1
            while j < k {
                let sum = sortedNums[i] + sortedNums[j] + sortedNums[k]
                if abs(target - result) > abs(target - sum) {
                    result = sum
                }
                
                if sum < target {
                    j += 1
                } else if sum > target{
                    k -= 1
                } else {
                    j += 1
                    k -= 1
                }
                
            }
        }
        
        return result
    }
}

Solution().threeSumClosest([0,1,2], 0)

//: [Next](@next)
