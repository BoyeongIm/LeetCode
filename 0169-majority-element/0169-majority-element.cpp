class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq;
        int majority = 0;
        for (auto n:nums) {
            freq[n]++;

            if (freq[n] > nums.size()/2) {
                majority = n;
                break;
            }
        }

        return majority;
    }
};