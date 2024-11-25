class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>> frequency;
        for (int i=0; i<mat.size(); i++) {
            frequency.push(accumulate(mat[i].begin(), mat[i].end(),0));
        }
        vector<int> answer;
        for (int i=0; i<k; i++) {
            auto p = frequency.top();
            frequency.pop();
            answer.push_back(p[1]);
        } return answer;
    }
};