class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int org_r = mat.size();
        int org_c = mat[0].size();
        if (r * c != org_r*org_c)
            return mat;
        if (r == org_r && c == org_c)
            return mat;

        vector<vector<int>> new_mat(r, vector<int>(c,0));

        int row = 0;
        int col = 0;

        for (int i=0; i<org_r; i++) {
            for (int j=0; j<org_c; j++) {
                new_mat[row][col] = mat[i][j];
                col ++;

                if (col==j) {
                    row++;
                    col=0; // 다음 row로 넘어가면서 col이 초기화되어야 함.
                }
            }
        }
        
        return new_mat;
        
        /*
        vector<int> to_1d;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                to_1d.push_back(mat[i][j]);
            }
        }

        vector<vector<int>> new_mat;
        for (int i = 0; i < r; i++) {
            vector<int> row(c);
            for (int j = 0; j < c; j++) {
                row[j] = to_1d[c * i + j];
            }
            new_mat.push_back(row);
        }

        return new_mat;*/
    }
};