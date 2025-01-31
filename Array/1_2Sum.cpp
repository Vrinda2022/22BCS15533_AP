class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> sum;
        int len = nums.size();
        int temp = 0;
        for(int i = 0; i < len; i++){
            temp = target-nums[i];
            for(int j = i+1; j < len; j++){
                if(temp == nums[j]){
                    sum.push_back(j);
                    sum.push_back(i);
                }
            
            }
        }
        return sum;
    }
};