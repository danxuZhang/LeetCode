/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
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
    ListNode* merge_sort(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* prev = nullptr;
        ListNode* fast = head;
        ListNode* slow = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            fast = fast->next->next;
            slow = slow->next;
        }

        prev->next = nullptr;  // set left_tail null
        ListNode* left_head = head;
        ListNode* right_head = slow;

        left_head = merge_sort(left_head);
        right_head = merge_sort(right_head);

        return merge(left_head, right_head); 
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        if (left == nullptr && right == nullptr) {
            return nullptr;
        }

        ListNode* dummy = new ListNode(-1, nullptr);
        ListNode* ptr = dummy;

        while (left != nullptr && right != nullptr) {
            if (left->val < right->val) {
                ptr->next = left;
                left = left->next;
            } else {
                ptr->next = right;
                right = right->next;
            }
            ptr = ptr->next;
        }

        while (left != nullptr) {
            ptr->next = left;
            left = left->next;
            ptr = ptr->next;
        }

        while (right != nullptr) {
            ptr->next = right;
            right = right->next;
            ptr = ptr->next;
        }
        
        ptr->next = nullptr;
        ListNode* res = dummy->next;
        delete(dummy);  // avoid memory leak
        return  res;
    }
public:
    ListNode* sortList(ListNode* head) {
        return merge_sort(head);    
    }
};
// @lc code=end

