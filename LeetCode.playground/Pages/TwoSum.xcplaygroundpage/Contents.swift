//: Playground - noun: a place where people can play

import Foundation

class Solution {
    func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
        var numDic = [Int: Int]()
        
        for index in 0..<nums.count {
            let num = target - nums[index]
            if  let tmp = numDic[num] {
                let result = [tmp,index]
                return result
            }
            numDic[nums[index]] = index
        }
        
        return [Int]()
    }
}

let testNum = [9, 2, 3, 5, 8, -1]

let result = Solution().twoSum(testNum, 8)

print("\(result)")

print("\(testNum[2]),\(testNum[3])")
