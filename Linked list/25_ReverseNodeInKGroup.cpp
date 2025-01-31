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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head; 
        
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prevGroupEnd = dummy, *curr = head;
        
        int length = 0;
        while (curr) { 
            length++;
            curr = curr->next;
        }
        
        curr = head;
        while (length >= k) {
            ListNode *groupStart = curr;
            ListNode *prev = nullptr;
            
            for (int i = 0; i < k; ++i) {
                ListNode *nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
            }
            
            prevGroupEnd->next = prev;
            groupStart->next = curr;
            
            prevGroupEnd = groupStart;
            
            length -= k;
        }
        
        return dummy->next;
    }
};