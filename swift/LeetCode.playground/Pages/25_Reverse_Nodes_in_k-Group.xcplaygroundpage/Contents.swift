//: [Previous](@previous)
//https://leetcode.com/problems/reverse-nodes-in-k-group/

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
    
    func length(list :ListNode?) -> Int {
        var cur = list
        var length = 0
        while cur != nil {
            length = length + 1
            cur = cur?.next
        }
        
        return length
    }
    
    func nodeAt(list: ListNode?, index: Int) -> ListNode? {
        var count = 0
        var head = list
        while count < index {
            head = head?.next
            count += 1
        }
        
        return head
    }
    
    func reverseList(list head: ListNode?, length length: Int) -> (ListNode?, ListNode?) {
        var reverseCount = 0;
        var currentNode = head
        var nextNode = currentNode?.next
        
        while nextNode != nil && reverseCount < length - 1 {
            let thirdNode = nextNode?.next
            
            nextNode?.next = currentNode
            
            currentNode = nextNode
            nextNode = thirdNode
            reverseCount += 1
        }
        head?.next = nil
        return (currentNode, head)
    }
    
    func reverseKGroup(_ head: ListNode?, _ k: Int) -> ListNode? {
        guard length(list: head) >= k else {
            return head
        }
        
        var res = head
        var pre_tail = head
        var cur_group = head
        var next_group = nodeAt(list: cur_group, index: k)
        
        if length(list: cur_group) >= k {
            let (group_head, group_tail) = reverseList(list: head, length: k)
            group_tail?.next = next_group
            pre_tail = group_tail
            res = group_head
        }
        
        cur_group = next_group
        
        while cur_group != nil {
            next_group = nodeAt(list: cur_group, index: k)
            if length(list: cur_group) >= k {
                let (group_head, group_tail) = reverseList(list: cur_group, length: k)
                group_tail?.next = next_group
                pre_tail?.next = group_head
                
                pre_tail = group_tail
            }
            cur_group = next_group
        }
        
        return res
    }
}

var list1 = ListNode(1)
list1.next = ListNode(2)
//list1.next?.next = ListNode(3)
//list1.next?.next?.next = ListNode(4)
//list1.next?.next?.next?.next = ListNode(5)

list1.message()

//Solution().reverseList(list: list1, length: 2).0?.message()
Solution().reverseKGroup(list1, 2)?.message()



//: [Next](@next)
