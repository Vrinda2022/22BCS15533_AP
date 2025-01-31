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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m, vector<int>(n, -1));
        
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int dir = 0;
        
        int x = 0, y = 0; 
        ListNode* current = head;
        
        while (current) {
            matrix[x][y] = current->val;
            current = current->next;
            
            int nextX = x + directions[dir].first;
            int nextY = y + directions[dir].second;
            
            if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n || matrix[nextX][nextY] != -1) {
                dir = (dir + 1) % 4;
                nextX = x + directions[dir].first;
                nextY = y + directions[dir].second;
            }
            
            x = nextX;
            y = nextY;
        }
        
        return matrix;
    }
};