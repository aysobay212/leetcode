//
// Created by ayden on 19/07/2026.
//
#include <vector>
#include <iostream>
using namespace std;

// i feel like this problem was quite straight-forward. just understanding the syntactical aspect to
// C++ was the biggest hurdle here
// the solution runs in O(n)

/**
 * Definition for singly-linked list.
 */

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {
    }

    ListNode(int x) : val(x), next(nullptr) {
    }

    ListNode(int x, ListNode *next) : val(x), next(next) {
    }
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // keep adding until both nodes point to none
        ListNode* head = new ListNode(0);
        ListNode* current = head;

        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {

            // null-coleascening, if there's a next, we go, otherwise set to 0
            int x = (l1 != nullptr) ? l1->val : 0;
            int y = (l2 != nullptr) ? l2->val : 0;

            int sum = x + y + carry;

            int digit = sum % 10;
            carry = sum / 10;

            current->next = new ListNode(digit);
            current = current->next;

            if (l1 != nullptr)
                l1 = l1->next;

            if (l2 != nullptr)
                l2 = l2->next;
        }

        return head->next;



    }
};


int main() {
    Solution s;

    ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));


    ListNode* result = s.addTwoNumbers(l1, l2);
    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    // format the output
}
