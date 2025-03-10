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
    int length(ListNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return 1 + length(root->next);
    }

    int getDecimalValue(ListNode* head) {
        int len = length(head);
        len -= 1;            
        int ans = 0;

        while (head) {      
            ans += (head->val * (1 << len));
            len -= 1;         
            head = head->next; 
        }
        return ans;
    }
};
