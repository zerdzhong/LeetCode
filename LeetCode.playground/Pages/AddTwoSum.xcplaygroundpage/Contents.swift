//: [Previous](@previous)

import Foundation


//  Definition for singly-linked list.

public class ListNode {
    public var val: Int
    public var next: ListNode?
    public init(_ val: Int) {
        self.val = val
        self.next = nil
    }
}

class Solution {
    func addTwoNumbers(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
        let resultList = ListNode(0)
        var resultNode: ListNode? = resultList
        var head1 = l1, head2 = l2
        var carry = 0
        
        while head1 != nil || head2 != nil || carry != 0{
            
            let sum = (head1 == nil ? 0:head1!.val) + (head2 == nil ? 0:head2!.val) + carry
            
            resultNode?.next = ListNode(sum % 10)
            carry = sum / 10
            
            head1 = head1?.next
            head2 = head2?.next
            resultNode = resultNode?.next
        }
        
        
        return resultList.next
    }
}

let testList1 = ListNode(1)
//testList1.next = ListNode(3)
//testList1.next?.next = ListNode(4)

let testList2 = ListNode(9)
testList2.next = ListNode(9)
//testList2.next?.next = ListNode(7)

let result = Solution().addTwoNumbers(testList1, testList2)

print("\(result?.val),\(result?.next?.val),\(result?.next?.next?.val)")

//: [Next](@next)
