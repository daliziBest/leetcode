//和054差不多

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<int> a(n, 0);
        vector<vector<int>> result(n, a);

        int gap = 0;
        int count = 1;
        int i = 0;
        int j = 0;
        while (true) {
            //→
            while (j < n - gap) {
                result[i][j] = count;
                count++;
                j++;
            }
            j--;
            i++;
            if (i >= n - gap) {
                break;
            }
            //↓
            while (i < n - gap) {
                result[i][j] = count;
                count++;
                i++;
            }
            i--;
            j--;
            if (j < gap) {
                break;
            }
            //←
            while (j >= gap) {
                result[i][j] = count;
                count++;
                j--;
            }
            j++;
            i--;
            gap++;
            if (i < gap) {
                break;
            }
            //↑
            while (i >= gap) {
                result[i][j] = count;
                count++;
                i--;
            }
            i++;
            j++;
            if (j >= n - gap) {
                break;
            }
        }

        return result;
    }
};