//二分查找

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int begin = 0;
        int end = m * n - 1;
        int mid;
        int rowindex;
        int colindex;
        while (begin <= end) {
            mid = (begin + end) / 2;
            rowindex = mid / n;
            colindex = mid % n;
            if (matrix[rowindex][colindex] == target) {
                return true;
            } else if (matrix[rowindex][colindex] < target) {
                begin = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return false;
    }
};