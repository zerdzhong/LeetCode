//: [Previous](@previous)
//https://leetcode.com/problems/swap-nodes-in-pairs/

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
    func swapPairs(_ head: ListNode?) -> ListNode? {
        
        guard let firstNode = head, let secondNode = firstNode.next else {
            return head
        }
        
        let thirdNode = secondNode.next
        secondNode.next = head
        firstNode.next = swapPairs(thirdNode)

        return secondNode
    }
}

var list1 = ListNode(1)
list1.next = ListNode(6)
list1.next?.next = ListNode(7)
list1.next?.next?.next = ListNode(8)

list1.message()

Solution().swapPairs(list1)?.message()

//: [Next](@next)
