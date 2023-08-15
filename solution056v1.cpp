//使用链表完成操作
//假设[a1,b1],[a2,b2],[a3,b3]...sepertated, 插入一个[a0,b0], 且a0 <= a1, 如何merge？
//具体实现
//使用list库，虽然forward_list空间效率更好，但是其不支持前向插入，它的是后向插入insert_after()
//双向iterator支持++和--操作，但不支持+和-操作
//O(n2)

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        list<vector<int>> intervalInList(1, intervals.at(0));

        int left;
        int right;
        for (int i = 1; i < intervals.size(); i++) {
            //new interval : [left, right]
            left = intervals[i][0];
            right = intervals[i][1];

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
                continue;
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
        }


        vector<vector<int>> result;
        for (auto i = intervalInList.cbegin(); i != intervalInList.cend(); i++) {
            result.push_back(*i);
        }
        return result;
    }
};