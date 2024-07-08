class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> answer(rowIndex+1);
        answer[0] = {1};
        for (int i=1; i<=rowIndex; i++) {
            answer[i].resize(i+1); // resize!!!!!!! 미친
            answer[i][0] = 1;
            answer[i][i] = 1;
            for (int j=1; j<i; j++) {
                answer[i][j] = answer[i-1][j-1] + answer[i-1][j];
            }
        }

        return answer[rowIndex];
    }
};