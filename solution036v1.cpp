//brutal method
//scan the board three times

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<bool> indicator;
        for (int i = 0; i < 9; i++) {
            indicator.push_back(false);
        }

        //check every row
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    if (indicator.at(num - 1) == true) {
                        return false;
                    } else {
                        indicator.at(num - 1) = true;
                    }
                }
            }

            resetIndicator(indicator);
        }

        //check every column
        for (int j = 0; j < 9; j++) {
            for (int i = 0; i < 9; i++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    if (indicator.at(num - 1) == true) {
                        return false;
                    } else {
                        indicator.at(num - 1) = true;
                    }
                }
            }
            
            resetIndicator(indicator);
        }

        //check every 3*3-sub-box
        for (int k = 0; k < 9; k++) {
            int baseRow = k / 3 * 3;
            int baseColunm = k % 3 * 3;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (board[baseRow + i][baseColunm + j] != '.') {
                        int num = board[baseRow + i][baseColunm + j] - '0';
                        if (indicator.at(num - 1) == true) {
                            return false;
                        } else {
                            indicator.at(num - 1) = true;
                        }
                    }
                }
            }

            resetIndicator(indicator);
        }
        
        return true;
    }
private:
    void resetIndicator(vector<bool>& indicator) {
        for(int i = 0; i < indicator.size(); i++) {
            indicator.at(i) = false;
        }
    }
};