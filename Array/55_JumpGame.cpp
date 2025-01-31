class Solution {
public:
    bool canJump(vector<int>& nums) {
        int MAX = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            if(i>MAX){
                return false;
            }
            MAX = max(MAX, i+nums[i]);
        }
        return true;
    }
};