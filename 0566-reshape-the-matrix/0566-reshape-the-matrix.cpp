class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if (r*c != mat.size()*mat[0].size()) return mat;
        if (r==mat.size() && c==mat[0].size()) return mat;

        vector<int> to_1d;
        for (int i=0; i<mat.size(); i++) {
            for (int j=0; j<mat[0].size(); j++) {
                to_1d.push_back(mat[i][j]);
            }
        }
        
        vector<vector<int>> new_mat;
        for (int i=0; i<r; i++) {
            vector<int> row(c);
            for (int j=0; j<c; j++) {
                row[j] = to_1d[c*i+j];
            }
            new_mat.push_back(row);
        }

        return new_mat;
    }
};