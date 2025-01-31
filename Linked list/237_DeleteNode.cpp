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
    void deleteNode(ListNode* node) {
        if (node == nullptr || node->next == nullptr) return;

        node->val = node->next->val;  // Copy next node's value
        ListNode* temp = node->next;  // Store reference to delete later
        node->next = node->next->next;  // Bypass next node
        delete temp;  // Delete the skipped node
    }
};
