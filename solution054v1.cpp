//不借助额外空间搞定循环终止条件
//弄清楚何时遍历完成

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int i = 0;
        int j = 0;
        int gap = 0;
        int endrow = matrix.size();
        int endcol = matrix.at(0).size();

        //core code
        while (true) {
            //→
            if (j == endcol - gap) {
                break;
            }
            do {
                result.push_back(matrix[i][j]);
                j++;
            } while (j < endcol - gap);
            i++;
            j--;

            //↓
            if (i == endrow - gap) {
                break;
            }
            do {
                result.push_back(matrix[i][j]);
                i++;
            } while (i < endrow - gap);
            j--;
            i--;

            //←
            if (j < 0 + gap) {
                break;
            }
            do {
                result.push_back(matrix[i][j]);
                j--;
            } while (j >= 0 + gap);
            i--;
            j++;
            gap++;

            //↑
            if (i < 0 + gap) {
                break;
            }
            do {
                result.push_back(matrix[i][j]);
                i--;
            } while (i >= 0 + gap);
            j++;
            i++;
        }

        return result;
    }
};