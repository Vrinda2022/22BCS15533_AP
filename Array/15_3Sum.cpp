class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (nums[j] > nums[j + 1]) {
                    int temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                }
            }
        }
        vector<vector<int>> result;

    for (int i = 0; i < nums.size() - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int l = i + 1;
        int r = nums.size() - 1;

        while (l < r) {
            int three_sum = nums[i] + nums[l] + nums[r];

            if (three_sum == 0) {
                result.push_back({nums[i], nums[l], nums[r]});

                while (l < r && nums[l] == nums[l + 1]) l++;
                while (l < r && nums[r] == nums[r - 1]) r--;

                l++;
                r--;
            } else if (three_sum < 0) {
                l++;
            } else {
                r--;
            }
        }
    }

    return result;
    }
};