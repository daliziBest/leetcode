//分割出ratings里所有的严格递增，递减，相等子数列
//分割细节需要仔细分析

class Solution {
public:
    int candy(vector<int>& ratings) {
        int numOfCandy = 0;
        int n;  //统计项数
        int i = 0;  //start point
        int memory = -1; //处理峰点

        if (ratings.size() == 1) {
            return ++numOfCandy;
        } else if (ratings[i] < ratings[i + 1]) {
            goto calUp;
        } else if (ratings[i] > ratings[i + 1]) {
            goto calDown;
        } else {
            goto calEqual;
        }

    calUp:
        n = 0;
        while (i + 1 < ratings.size() && ratings[i] < ratings[i + 1]) {
            n++;
            i++;
        }
        if (i + 1 >= ratings.size()) { //end
            i++;
            n++;
            numOfCandy += n * (n + 1) / 2;
            return numOfCandy;
        } if (ratings[i] == ratings[i + 1]) { //equal
            i++;
            n++;
            numOfCandy += n * (n + 1) / 2;
            goto calEqual;
        } else { //down
            numOfCandy += n * (n + 1) / 2;
            memory = n + 1;
            goto calDown;
        }

    calDown: //最复杂
        n = 0;
        while (i + 1 < ratings.size() && ratings[i] > ratings[i + 1]) {
            i++;
            n++;
        }
        if (i + 1 >= ratings.size() || ratings[i] == ratings[i + 1]) {//end or equal
            i++;
            n++;
            if (memory <= n) {
                numOfCandy += n * (n + 1) / 2;
            } else {
                numOfCandy += memory + (n - 1) * n / 2;
            }
            memory = -1;
            if (i >= ratings.size()) {
                return numOfCandy;
            } else {
                goto calEqual;
            }
        } else { //up
            if (memory <= n + 1) {
                numOfCandy += n * (n + 3) / 2;
            } else {
                numOfCandy += memory + (n - 1) * (2 + n) / 2;
            }
            memory = -1;
            goto calUp;
        }

    calEqual:
        n = 0;
        while (i + 1 < ratings.size() && ratings[i] == ratings[i + 1]) {
            i++;
            n++;
        }
        if (i + 1 >= ratings.size()) { //end
            n++;
            numOfCandy += n;
            return numOfCandy;
        } else if (ratings[i] < ratings[i + 1]){ //up
            numOfCandy += n;
            goto calUp;
        } else { //down
            numOfCandy += n;
            goto calDown;
        }
    }
};