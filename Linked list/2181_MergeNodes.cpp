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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy = new ListNode(); 
        ListNode* current = dummy;
        ListNode* temp = head->next;
        
        int sum = 0;
        while (temp) {
            if (temp->val == 0) { 
                if (sum > 0) { 
                    current->next = new ListNode(sum);
                    current = current->next;
                    sum = 0; 
                }
            } else {
                sum += temp->val;
            }
            temp = temp->next;
        }
        
        return dummy->next;
    }
};
