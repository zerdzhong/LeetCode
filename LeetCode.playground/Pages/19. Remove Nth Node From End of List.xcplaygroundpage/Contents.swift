//: [Previous](@previous)
//https://leetcode.com/problems/remove-nth-node-from-end-of-list/

import Foundation


// Definition for singly-linked list.

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
    func removeNthFromEnd(_ head: ListNode?, _ n: Int) -> ListNode? {
        
        var preTargetNode = head!
        var endNode = head!
        var preTargetDistance = 0
        
        while endNode.next != nil {
            
            endNode = endNode.next!
            
            if preTargetDistance < n {
                preTargetDistance += 1
            } else {
                preTargetNode = preTargetNode.next!
            }
        }
        
        if let tagetNode = preTargetNode.next, preTargetDistance == n {
            preTargetNode.next = tagetNode.next
            return head
        } else if preTargetDistance == n - 1 {
            return head?.next
        }
        
        return nil
    }
}

let list = ListNode(1)
list.next = ListNode(2)
//list.next?.next =  ListNode(3)
list.message()
Solution().removeNthFromEnd(list, 2)?.message()

//: [Next](@next)
