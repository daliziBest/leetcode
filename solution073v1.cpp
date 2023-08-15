//follow up 1: m*n -1 matrix
//follow up 2: m+n indicate if the row or column need to be set 0
//follow up 3: Store hash in the first row and first column of the matrix.

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int col0 = -1;
        int row0 = -1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    if (i != 0 && j != 0) {
                        matrix[i][0] = 0;
                        matrix[0][j] = 0;
                        continue;
                    }
                    //easy to be ignored !!!
                    if (i == 0) {
                        row0 = 0;
                    }
                    if (j == 0) {
                        col0 = 0;
                    }
                }
            }
        }
        
        //set 0, the handle order needs to be careful
        //handle all column
        for (int j = 1; j < n; j++) {
            if (matrix[0][j] == 0) {
                int i = 1;
                while (i < m) {
                    matrix[i][j] = 0;
                    i++;
                }
            }
        }
        //handle all row
        for (int i = 1; i < m; i++) {
            if (matrix[i][0] == 0) {
                int j = 1;
                while (j < n) {
                    matrix[i][j] = 0;
                    j++;
                }
            }
        }

        if (col0 == 0) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
            
        }
        if (row0 == 0) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
    }
};