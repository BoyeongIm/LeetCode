class Solution {
public:
    static bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second == b.second) return a.first > b.first;
        return a.second < b.second;
    }

    vector<int> frequencySort(vector<int>& nums) {
        map<int, int> frequency;
        for (auto n : nums) {
            if (frequency.find(n)==frequency.end()) {
                frequency[n] = 1;
            } else frequency[n] ++;
        }

        vector<pair<int,int>> freq2(frequency.begin(), frequency.end());
        sort(freq2.begin(), freq2.end(), cmp);
        vector<int> answer;

        for (auto p : freq2) {
            while (p.second > 0) {
                answer.push_back(p.first);
                p.second--;
            }
        }

        return answer;
    }
};