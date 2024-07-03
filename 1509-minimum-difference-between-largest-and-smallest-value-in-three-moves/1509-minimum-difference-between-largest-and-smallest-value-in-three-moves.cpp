class Solution {
public:
    int minDifference(vector<int>& nums) {
        /* if (nums.size() > 3) {
            int min_idx = min_element(nums.begin(), nums.end()) - nums.begin();
            int count = 0;
            while (count < 3) {
                int max_idx = max_element(nums.begin(), nums.end()) - nums.begin();
                nums[max_idx] = nums[min_idx];
                count++;
            }
            int max_idx = max_element(nums.begin(), nums.end()) - nums.begin();
            int diff = nums[max_idx] - nums[min_idx];
            return diff;
        }
        return 0; */

        if (nums.size() <= 4) return 0;
        int n = nums.size();
        sort(nums.begin(), nums.end()); 
        // sorting을 해서, 가장 작은 것부터~혹은 가장 큰 것부터 일정 개수 만큼 (총 최대 3개) 바꾸기
        int min_diff = min({nums[n-1]-nums[3], // 제일 작은 3개를 바꾸기
                            nums[n-2]-nums[2], // 제일 큰거 1개, 제일 작은 2개 바꾸기
                            nums[n-3]-nums[1], // 제일 큰거 2개, 제일 작은 1개 바꾸기
                            nums[n-4]-nums[0]}); // 제일 큰 3개 바꾸기 
        return min_diff;
    }
};