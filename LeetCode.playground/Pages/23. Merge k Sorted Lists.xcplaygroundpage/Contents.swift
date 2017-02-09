//: [Previous](@previous)
//https://leetcode.com/problems/merge-k-sorted-lists/

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
    func mergeKLists(_ lists: [ListNode?]) -> ListNode? {
        return partition(lists, 0, lists.count - 1)
    }
    
    func partition(_ lists: [ListNode?],_ s: Int, _ e: Int) -> ListNode? {
        if (s==e)  {
            return lists[s];
        }
        if (s<e) {
            let q=(s+e)/2;
            let l1=partition(lists,s,q);
            let l2=partition(lists,q+1,e);
            return mergeTwoLists(l1,l2);
        }
        
        return nil;
    }
    
    func mergeTwoLists(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
        if l1 == nil {
            return l2
        }
        if l2 == nil {
            return l1
        }
        
        if l1!.val < l2!.val {
            l1!.next = mergeTwoLists(l1!.next, l2)
            return l1
        } else {
            l2!.next = mergeTwoLists(l1, l2!.next)
            return l2
        }
    }
}


var list1 = ListNode(1)
list1.next = ListNode(6)
list1.next?.next = ListNode(7)


var list2 = ListNode(4)
list2.next = ListNode(5)
list2.next?.next = ListNode(8)


var list3 = ListNode(3)
list3.next = ListNode(6)
list3.next?.next = ListNode(9)

var list4 = ListNode(1)
var list5 = ListNode(1)
var list6 = ListNode(1)
var list7 = ListNode(1)

Solution().mergeKLists([list1, list2, list3, list4, list5, list6, list7])?.message()

//: [Next](@next)
