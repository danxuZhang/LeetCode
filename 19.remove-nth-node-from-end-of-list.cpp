/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 */

// @lc code=start
class Solution {
  public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }

        ListNode *slow = head;
        ListNode *fast = head;

        for (int i = 0; i < n; ++i) {
            fast = fast->next;
        }

        if (fast == nullptr) {
            return head->next;
        }

        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        slow->next = slow->next->next;

        return head;
    }
};
// @lc code=end
