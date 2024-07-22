class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        map<int, int, greater<int>> kthscore;
        for (int r=0; r<score.size(); r++) 
            kthscore[score[r][k]] = r;
        
        vector<vector<int>> sorted_result;
        for (auto it=kthscore.begin(); it!=kthscore.end(); it++)
            sorted_result.push_back(score[it->second]);
        return sorted_result;
    }
};