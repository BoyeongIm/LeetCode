class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans;
        sort(nums.begin(), nums.end());

        for (size_t i=0; i<nums.size(); i++) {
            if (nums[i] == nums[i+1]) {
                ans = nums[i];
                break;
            }
        }

        return ans;
    }
};