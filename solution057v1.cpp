//056的简单版

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        //corner case
        vector<vector<int>> result;
        if (intervals.size() == 0){
            result.push_back(newInterval);
            return result;
        }

        list<vector<int>> intervalInList(intervals.cbegin(), intervals.cend());
        //new interval : [left, right]
        int left = newInterval.at(0);
        int right = newInterval.at(1);

        //find insert location
        auto insertLoc = intervalInList.begin();
        //for ( ; insertLoc != intervalInList.end(); ) {
        while (insertLoc != intervalInList.end()) {
            if (left <= (*insertLoc).at(0)) {
                //insert [left,right], then to merge
                insertLoc = intervalInList.insert(insertLoc, {left, right});
                break;
            } else if (left <= (*insertLoc).at(1)) {
                //insert [insertLoc.left, right], then to merge
                insertLoc = intervalInList.insert(insertLoc, {(*insertLoc).at(0), right});
                break;
            } else {
                insertLoc++;
            }
        }
        if (insertLoc == intervalInList.end()) {
            //insert [left, right] at the end
            intervalInList.insert(insertLoc, {left, right});
            //由于后面定义了next，无法使用goto跳过
            for (auto i = intervalInList.cbegin(); i != intervalInList.cend(); i++) {
                result.push_back(*i);
            }
            return result;
        }
        
        //merge
        //auto next = insertLoc + 1; //错误!!!双向迭代器只支持++，不支持+运算
        //auto next = insertLoc++;  //错误!!!先赋值，再加1
        auto next = ++insertLoc;
        insertLoc--;
        //for ( ; next != intervalInList.end(); ) {
        while (next != intervalInList.end()) {
            if (right < (*next).at(0)) {
                break;
            } else if (right <= (*next).at(1)) {
                (*insertLoc).at(1) = (*next).at(1);
                intervalInList.erase(next);
                break;
            } else {
                next = intervalInList.erase(next);
            }
        }

        //when merge is done
        for (auto i = intervalInList.cbegin(); i != intervalInList.cend(); i++) {
            result.push_back(*i);
        }
        return result;
    }
};