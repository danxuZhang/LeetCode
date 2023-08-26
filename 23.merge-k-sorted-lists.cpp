/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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
    ListNode *merge2Lists(ListNode *l1, ListNode *l2) {
        if (l1 == nullptr && l2 == nullptr) {
            return nullptr;
        }
        if (l1 == nullptr) {
            return l2;
        }
        if (l2 == nullptr) {
            return l1;
        }

        ListNode *dummy = new ListNode(-1, nullptr);
        ListNode *ptr   = dummy;
        ListNode *nxt;

        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                nxt       = l1->next;
                ptr->next = l1;
                l1->next  = nullptr;
                l1        = nxt;
                ptr       = ptr->next;
            } else {
                nxt       = l2->next;
                ptr->next = l2;
                l2->next  = nullptr;
                l2        = nxt;
                ptr       = ptr->next;
            }
        }

        if (l1 != nullptr) {
            ptr->next = l1;
        }

        if (l2 != nullptr) {
            ptr->next = l2;
        }

        ListNode *res = dummy->next;
        delete (dummy);
        return res;
    }

  public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int n = lists.size();

        if (n == 0) {
            return nullptr;
        }

        while (n > 1) {
            for (int i = 0; i < n / 2; ++i) {
                lists[i] = merge2Lists(lists[i], lists[n - i - 1]);
            }
            n = (n + 1) / 2;
        }

        return lists[0];
    }
};
// @lc code=end
