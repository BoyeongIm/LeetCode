class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if (nums.size()==2) return {0,1};

        vector<int> idx(2);

        for (int i=0; i<nums.size(); i++) {
            int end=nums.size()-1;
            while (i<end) {
                if (nums[i]+nums[end]==target) {
                    return {i, end};
                }
                end--;
            }
        }

        return {};
    }
};