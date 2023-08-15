//参考https://introcs.cs.princeton.edu/java/assignments/collinear.html
//angle保存斜率
//先转化象限，再计算斜率
//https://cplusplus.com/reference/cfloat/

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if (points.size() <= 2) {
            return points.size();
        }

        int result = 0;
        vector<double> angle(points.size() - 1, 0);
        for (int origin = 0; origin < points.size(); origin++) {
            int i = 0;
            for (int j = 0; j < points.size(); j++) {
                if (j == origin) {
                    continue;
                }
                
                int ydif = points[j][1] - points[origin][1];
                int xdif = points[j][0] - points[origin][0];
                //转化象限
                // if (xdif < 0) {
                //     ydif *= -1;
                //     xdif *= -1;
                // }
                //计算斜率
                if (xdif == 0) {
                    angle[i++] = DBL_MAX;
                } else {
                    angle[i++] = (double)ydif / xdif;
                }
            }

            sort(angle.begin(), angle.end());
            
            i = 1;
            int numOfSame = 1;
            int maxNumOfSame = 1;
            while (i < angle.size()) {
                if (angle[i] == angle[i - 1]) {
                    i++;
                    numOfSame++;
                } else {
                    i++;
                    maxNumOfSame = numOfSame > maxNumOfSame ? numOfSame : maxNumOfSame;
                    numOfSame = 1;
                }
            }
            maxNumOfSame = numOfSame > maxNumOfSame ? numOfSame : maxNumOfSame;
            maxNumOfSame++;
            result = maxNumOfSame > result ? maxNumOfSame : result;
        }

        return result;
    }
};