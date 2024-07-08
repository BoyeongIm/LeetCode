class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> answer;
        for (int i=0; i<rowIndex+1; i++) {
            vector<int> row(i+1, 1);
            answer.push_back(row);
        }

        for (int j=1; j<rowIndex; j++) {
            for (int k=0; k<j; k++) {
                answer[j+1][k+1] = answer[j][k]+answer[j][k+1];
            }
        }

        return answer[rowIndex];
    }
};