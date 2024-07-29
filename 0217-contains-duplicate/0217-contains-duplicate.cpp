class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> nums_set;
        for (auto n : nums) {
            if (nums_set.find(n)==nums_set.end())
                nums_set.insert(n);
            else return true;
        }

        return false;
    }
};