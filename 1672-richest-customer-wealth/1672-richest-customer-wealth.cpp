class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max = 0;
        for (int i=0; i<accounts.size(); i++) {
            int answer = 0;
            for (int j =0; j<accounts[i].size(); j++) {
                answer += accounts[i][j];
            }
            if (max < answer) max = answer;
        }
        return max;
    }
};