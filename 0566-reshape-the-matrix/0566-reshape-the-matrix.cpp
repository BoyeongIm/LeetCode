class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int org_r = mat.size();
        int org_c = mat[0].size();
        if (r * c != org_r * org_c)
            return mat;
        if (r == org_r && c == org_c)
            return mat;

        vector<int> to_1d;
        for (int i = 0; i < org_r; i++) {
            for (int j = 0; j < org_c; j++) {
                to_1d.push_back(mat[i][j]); // 주어진 matrix를 1차원으로 펼침
            }
        }

        vector<vector<int>> new_mat;
        for (int i = 0; i < r; i++) {
            vector<int> row(c);
            for (int j = 0; j < c; j++) {
                row[j] =
                    to_1d[c * i +
                          j]; // 인덱스로 접근하기 때문에, row벡터를 우선 어떤
                              // 값을 갖는 벡터가 되도록 위에서 초기화해줘야 함.
                // 1차원으로 펼친 벡터에서, 몇번째를 가져와야 알맞게 가져오는지
                // 인덱스 비교 (새로 주어진 행렬의 크기에 따른 2차원 인덱스와,
                // 1차원 인덱스 교)
            }
            new_mat.push_back(row);
        }

        return new_mat;

        /* OTHER EASY SOLUTION
        vector<vector<int>> new_mat(r, vector<int>(c,0));

        int row = 0;
        int col = 0;

        for (int i=0; i<org_r; i++) {
            for (int j=0; j<org_c; j++) {
                new_mat[row][col] = mat[i][j];
                col ++;

                if (col==c) { // 한 행에서, 새로 주어진 c까지 도달하고 나면 다음
        행으로 넘어함 row++; col=0; // 다음 row로 넘어가면서 col이 초기화되어야
        함.
                }
            }
        }

        return new_mat;*/
    }
};