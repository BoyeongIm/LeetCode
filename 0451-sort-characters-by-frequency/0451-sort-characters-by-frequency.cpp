class Solution {
public:
    static bool cmp(pair<char, int>& a, pair<char, int>& b) {
        if (a.second == b.second) return a.first < b.first;
        return a.second > b.second;
    }
    string frequencySort(string s) {
        map<char, int> frequency;
        for (int i=0; i<s.length(); i++) {
            if (frequency.find(s[i])==frequency.end()) {
                frequency[s[i]] = 1;
            } else frequency[s[i]] ++;
        }
        
        vector<pair<char, int>> freq2(frequency.begin(), frequency.end());
        sort(freq2.begin(), freq2.end(), cmp);
        
        string s2 = "";
        for (auto p : freq2) {
            s2.append(p.second, p.first);
        }
        return s2;
    }
};