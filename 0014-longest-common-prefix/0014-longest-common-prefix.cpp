class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string std1 = strs[0];
        string std2 = strs[strs.size()-1];
        string prefix = "";
        for (int i=0; i<std1.size(); i++) {
            if (std1[i]==std2[i]) prefix += std1[i];
            else break;
        }

        return prefix;
    }
};