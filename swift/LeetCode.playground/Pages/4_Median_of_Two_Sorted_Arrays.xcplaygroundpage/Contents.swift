//: [Previous](@previous)
//: https://leetcode.com/problems/median-of-two-sorted-arrays/

import Foundation

class Solution {
    func findMedianSortedArrays(_ nums1: [Int], _ nums2: [Int]) -> Double {
        var newArray = [Int]()
        var index1 = 0, index2 = 0, totalCount = nums1.count+nums2.count
        var result: Double = 0
        
        for _ in 0..<totalCount {
            if index1 >= nums1.count {
                newArray.append(contentsOf: nums2.suffix(from: index2))
                break
            }
            if index2 >= nums2.count {
                newArray.append(contentsOf: nums1.suffix(from: index1))
                break
            }
            if nums1[index1] < nums2[index2] {
                newArray.append(nums1[index1])
                index1 += 1
            } else {
                newArray.append(nums2[index2])
                index2 += 1
            }
        }
        
        
        if totalCount % 2 == 1 {
            result = Double(newArray[totalCount/2])
        } else {
            result = Double(newArray[totalCount/2] + newArray[totalCount/2 - 1]) / 2
        }
        
//        print("\(result)")
        
        return result
    }
}

let test1 = [1, 2]
let test2 = [3, 4]

Solution().findMedianSortedArrays(test1, test2)

//: [Next](@next)
