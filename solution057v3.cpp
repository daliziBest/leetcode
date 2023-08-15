//v2解法不借助list
//提高了空间利用度

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        auto i = intervals.cbegin();
        while (i != intervals.cend()) {
            if (newInterval.at(1) < (*i).at(0) || (*i).at(1) < newInterval.at(0)) {
                if (newInterval.at(1) < (*i).at(0)) {
                    break;
                } else {
                    result.push_back(*i);
                    i++;
                }
            } else {
                newInterval.at(0) = newInterval.at(0) <= (*i).at(0) ? newInterval.at(0) : (*i).at(0);
                newInterval.at(1) = newInterval.at(1) >= (*i).at(1) ? newInterval.at(1) : (*i).at(1);
                i++;
            }
        }
        result.push_back(newInterval);
        while (i != intervals.cend()) {
            result.push_back(*i);
            i++;
        }

        return result;
    }
};