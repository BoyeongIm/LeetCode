class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_set<int> freq;
        for (auto n:nums) {
            if (freq.count(n)) freq[n]+=1;
            else freq[n]=1;

            if (freq[n] > nums.size()/2) return n;
        }
    }
};