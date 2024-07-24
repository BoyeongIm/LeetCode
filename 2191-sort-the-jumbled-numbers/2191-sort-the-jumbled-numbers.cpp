class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[1] == b[1]) return a[2] < b[2];
        return a[1] < b[1];
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<vector<int>> mapped_vals;
        for (int j=0; j<nums.size(); j++) {
            string tostr = to_string(nums[j]);
            string mapped = "";
            for (int i=0; i<tostr.size(); i++) {
                mapped += to_string(mapping[(tostr[i] -'0')]);
            } int mint = stoi(mapped);
            mapped_vals.push_back({nums[j], mint, j});
        }
        sort(mapped_vals.begin(), mapped_vals.end(), cmp);

        vector<int> answer;
        for (auto vec : mapped_vals) {
            answer.push_back(vec[0]);
        }

        return answer;
    }
};