class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums[0]>=target) return 0;
        if (nums[nums.size()-1]<target) return nums.size();

        int start = 0;
        int end = nums.size()-1;

        while(start<=end) {
            int mid = start + (end-start)/2;
            if (nums[mid]<target) start = mid+1;
            else end = mid-1;
        }

        if (nums[start]>=target) return start;
        else return start+1;
    }
};