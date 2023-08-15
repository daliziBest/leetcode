//如果可以使用another 2D matrix很简单，行转列即可
//rotate本质就是每一对四元组发生了移位
//如何根据一个点确定四元组的位置或者找到这个点rotate之后的位置
//利用坐标系帮助理解，假设某个点(i,j)，顺时针rotate90度之后的坐标应该为(j,-i)，数组位置为(j,n-1-i),逆时针转动90度的坐标应该为(-j,i),数组位置则为(n-1-j,i)

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rowNum;
        int colNum;
        if (matrix.size() % 2 == 0) {
            rowNum = (matrix.size() - 1) / 2;
            colNum = (matrix.size() - 1) / 2;
        } else {
            rowNum = (matrix.size() - 1) / 2 - 1;
            colNum = (matrix.size() - 1) / 2;
        }

        //依次处理每一对四元组,对它们进行rotate
        for (int i = 0; i <= rowNum; i++) {
            for (int j = 0; j <= colNum; j++) {
                rotateMini(matrix, i, j);
            }
        }
    }
    
private:
    void rotateMini(vector<vector<int>>& matrix, int i, int j) {
        int cache = matrix[i][j];
        int count = 0;
        do {
            count++;
            matrix[i][j] = matrix[matrix.size() - 1 - j][i];
            int temp = i;
            i = matrix.size() - 1 - j;
            j = temp;
        } while (count < 3);
        
        matrix[i][j] = cache;
    }
};