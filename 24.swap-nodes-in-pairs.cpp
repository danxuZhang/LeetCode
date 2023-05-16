/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }    

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr) {
            int tmp = slow->val;
            slow->val = fast->val;
            fast->val = tmp;
            slow = slow->next->next;
            if (fast->next != nullptr) {
                fast = fast->next->next;
            } else {
                break;
            }
        }

        return head;
    }
};
// @lc code=end

