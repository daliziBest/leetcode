//基于057v2的解法

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        list<vector<int>> intervalInList;
        for (auto i = intervals.cbegin(); i != intervals.cend(); i++) {
            insert(intervalInList, *i);
        }

        vector<vector<int>> result(intervalInList.cbegin(), intervalInList.cend());
        return result;
    }

private:
    void insert(list<vector<int>>& intervalInList, vector<int> newInterval) {
        auto insertLoc = intervalInList.begin();
        //find insert location
        while (insertLoc != intervalInList.end()) {
            //check if connected
            //if not connected
            if (newInterval.at(1) < (*insertLoc).at(0) || newInterval.at(0) > (*insertLoc).at(1)) {
                if (newInterval.at(1) < (*insertLoc).at(0)) {
                    break;
                } else {
                    insertLoc++;
                }
            } else {
                newInterval.at(0) = newInterval.at(0) <= (*insertLoc).at(0) ? newInterval.at(0) : (*insertLoc).at(0);
                newInterval.at(1) = newInterval.at(1) >= (*insertLoc).at(1) ? newInterval.at(1) : (*insertLoc).at(1);
                insertLoc = intervalInList.erase(insertLoc);
            }
        }
        intervalInList.insert(insertLoc, newInterval);

    }
};