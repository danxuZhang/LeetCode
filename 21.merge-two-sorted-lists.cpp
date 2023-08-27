/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 */

// @lc code=start
class Solution {
  public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        ListNode *dummy = new ListNode(-1, nullptr);

        ListNode *ptr  = dummy;
        ListNode *ptr1 = list1;
        ListNode *ptr2 = list2;

        ListNode *next;
        while (ptr1 != nullptr && ptr2 != nullptr) {
            if (ptr1->val < ptr2->val) {
                next       = ptr1->next;
                ptr1->next = nullptr;
                ptr->next  = ptr1;
                ptr1       = next;
                ptr        = ptr->next;
            } else {
                next       = ptr2->next;
                ptr2->next = nullptr;
                ptr->next  = ptr2;
                ptr2       = next;
                ptr        = ptr->next;
            }
        }

        while (ptr1 != nullptr) {
            next       = ptr1->next;
            ptr1->next = nullptr;
            ptr->next  = ptr1;
            ptr1       = next;
            ptr        = ptr->next;
        }

        while (ptr2 != nullptr) {
            next       = ptr2->next;
            ptr2->next = nullptr;
            ptr->next  = ptr2;
            ptr2       = next;
            ptr        = ptr->next;
        }

        ListNode *res = dummy->next;
        delete (dummy);
        return res;
    }
};
// @lc code=end
