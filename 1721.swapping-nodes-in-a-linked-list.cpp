/*
 * @lc app=leetcode id=1721 lang=cpp
 *
 * [1721] Swapping Nodes in a Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode *first, *second;
        ListNode* fast = head;
        ListNode* slow = head;

        for (int i = 1; i < k; ++i) {
            fast = fast->next;
        }


        first = fast;

        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        second = slow;

        int tmp = first->val;
        first->val = second->val;
        second->val = tmp;

        return head;
    }
};
// @lc code=end

