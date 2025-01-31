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
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false;

        ListNode *slow = head, *fast = head;

        while (fast && fast->next) {
            slow = slow->next;           // Move slow by 1 step
            fast = fast->next->next;     // Move fast by 2 steps
            
            if (slow == fast) return true; // Cycle detected
        }

        return false; // No cycle found
    }
};
