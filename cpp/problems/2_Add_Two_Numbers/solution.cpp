//
// Created by zhongzhendong on 2018-12-28.
//

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <vector>
#include <map>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode* n) : val(x), next(n) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto result_head = ListNode(0);

        auto sum = 0, carry = 0;
        auto head = &result_head;

        while (l1 || l2) {
            sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0)  + carry;

            head->next = new ListNode(sum % 10);
            carry = sum / 10;

            l1 = l1->next; l2 = l2->next; head = head->next;
        }

        if (carry > 0) {
            head->next = new ListNode(carry);
        }

        return result_head.next;
    }
};

TEST_CASE("AddTwoNumbers") {
    auto num1 = new ListNode(1, new ListNode(4, new ListNode(3)));
    auto num2 = new ListNode(5, new ListNode(6, new ListNode(4)));

    auto res = Solution().addTwoNumbers(num1, num2);

    REQUIRE(res->val == 6);
    REQUIRE(res->next->val == 0);
    REQUIRE(res->next->next->val == 8);

    num1 = new ListNode(1, new ListNode(8));
    num2 = new ListNode(0);

    res = Solution().addTwoNumbers(num1, num2);

    REQUIRE(res->val == 1);
    REQUIRE(res->next->val == 8);

}

