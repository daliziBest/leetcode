class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> current = {1};
        vector<int> before;
        for (int i = 1; i <= rowIndex; i++) {
            before = current;
            current.clear();
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) {
                    current.push_back(1);
                } else {
                    current.push_back(before[j - 1] + before[j]);
                }
            }
        }

        return current;
    }
};