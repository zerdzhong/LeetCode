//: [Previous](@previous)
//https://leetcode.com/problems/merge-two-sorted-lists/

import Foundation

/**
 * Definition for singly-linked list.
 */

public class ListNode {
    public var val: Int
    public var next: ListNode?
    public init(_ val: Int) {
        self.val = val
        self.next = nil
    }
    
    public func message() -> String{
        var msg = "\(self.val)"
        var nextNode = self
        while nextNode.next != nil {
            nextNode = nextNode.next!
            msg += "->\(nextNode.val)"
        }
        
        return msg
    }
}

class Solution {
    func mergeTwoLists(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
        
        if l1 == nil {
            return l2
        } else if l2 == nil{
            return l1
        }
        
        var node1 = l1, node2 = l2
        let dummyNode = ListNode(0)
        var resultNode = dummyNode
        
        while node1 != nil && node2 != nil {
            if node1!.val < node2!.val {
                resultNode.next = node1
                node1 = node1!.next
            } else {
                resultNode.next = node2
                node2 = node2!.next
            }
            
            resultNode = resultNode.next!
        }
        
        resultNode.next = (node1 != nil) ? node1 : node2
        
        return dummyNode.next
    }
}

var list1 = ListNode(1)
list1.next = ListNode(6)
list1.next?.next = ListNode(7)

list1.message()

var list2 = ListNode(4)
list2.next = ListNode(5)
list2.next?.next = ListNode(8)

list2.message()

Solution().mergeTwoLists(list1, list2)?.message()

//: [Next](@next)
