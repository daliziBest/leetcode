//另一种merge思路:假设有一堆水滴，来了一个新水滴，是怎么merge的?
//挨个看是否联通，联通就把旧水滴merge到新水滴中并删除旧水滴，直到看完，然后插入merge后的新水滴
//如果排好序，可以加快速度，不用每次都必须看完
//依旧使用list实现
//O(n)

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        list<vector<int>> intervalInList(intervals.cbegin(), intervals.cend());
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

        
        vector<vector<int>> result(intervalInList.cbegin(), intervalInList.cend());
        return result;
    }
};