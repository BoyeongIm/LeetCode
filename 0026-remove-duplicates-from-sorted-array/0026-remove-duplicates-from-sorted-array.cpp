class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size()==1) return 1;
        if (nums.size()==2 && nums[0]==nums[1]) return 1; 

        int i = 0;
        while (i<nums.size()-1) {
            if (nums[i]==nums[i+1]) {
                int idx = i+1;
                while (nums[idx]==nums[i] && idx<nums.size()) {
                    idx++;
                }
                nums.erase(nums.begin()+i+1, nums.begin()+idx);
            } else i++;            
        }

        return nums.size();
    }
};