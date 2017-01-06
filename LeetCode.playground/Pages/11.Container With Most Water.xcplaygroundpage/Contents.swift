//: [Previous](@previous)
//https://leetcode.com/problems/container-with-most-water/

import Foundation

class Solution {
    func maxArea(_ height: [Int]) -> Int {
        var maxArea = 0, curArea = 0
        var left = 0, right = height.count - 1
        
        while left < right {
            if height[left] < height[right] {
                curArea = height[left] * (right - left)
                left += 1
            } else if height[left] > height[right] {
                curArea = height[right] * (right - left)
                right -= 1
            } else {
                curArea = height[left] * (right - left)
                left += 1
                right -= 1
            }
            
            maxArea = max(maxArea, curArea)
        }
        
        return maxArea
    }
}

let testCase = [1,1]
Solution().maxArea(testCase)

//: [Next](@next)
