//从左向右划等高线，依次计算每个小水槽
//可能遇到最后画不出线，此时反过来从右向左划等高线，依次计算小水槽即可

class Solution {
public:
    int trap(vector<int>& height) {
        //corner case
        if (height.size() == 1 || height.size() == 2) {
            return 0;
        }

        int result = 0;
        int left = 0;
        int leftHeight;
        int right;
        
        //find the left of slot
    findLeft:    
        while (left <= height.size() - 3) {
            if (height.at(left) > height.at(left + 1)) {
                goto findRight;
            } else {
                left++;
            }
        }
        return result;

        //find the right of slot
    findRight:
        leftHeight = height.at(left);
        right = left + 2;
        while (right < height.size()) {
            if (height.at(right) >= leftHeight) {
                goto compWater;
            } else {
                right++;
            }
        }
        return trapInverse(height, left, result);
        //return result;

        //computer how much water this slot can trap
    compWater:    
        for (int i = left + 1; i < right; i++) {
            result += leftHeight - height.at(i);
        }
        
        //move left to right, continue
        left = right;
        goto findLeft;
    }
    
private:
    int trapInverse(vector<int>& height, int end, int result) {
        int right = height.size() - 1;
        int rightHeight;
        int left;
        
        //find the right of slot
    findRight:    
        while (right >= end + 2) {
            if (height.at(right - 1) < height.at(right)) {
                goto findLeft;
            } else {
                right--;
            }
        }
        return result;

        //find the left of slot
    findLeft:    
        rightHeight = height.at(right);
        left = right - 2;
        while (left >= end) {
            if (height.at(left) >= rightHeight) {
                break;
            } else {
                left--;
            }
        }

        //computer how much water this slot can trap
        for (int i = right - 1; i > left; i--) {
            result += rightHeight - height.at(i);
        }
        
        //move right to left, continue
        right = left;
        goto findRight;
    }
};