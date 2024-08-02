class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size()==1) return 1;
        for (int i=0; i<nums.size()-1; i++) {
            if (nums[i]==nums[i+1]) {
                int idx = i+1;
                while (nums[idx]==nums[i] && idx<nums.size()) 
                    nums.erase(nums.begin()+(idx));
                    idx++;
            }
        }
        return nums.size();
    }
};