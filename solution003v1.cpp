//滑动窗口，双指针

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0 || s.size() == 1)
        {
            return s.size();
        }

        unordered_map<char, int> char2index;
        int max_len = 1;
        int current_len = 1;

        char2index.insert({s[0], 0});
        int i = 0;
        int j = 1;
    label1:
        while (j < s.size() && !char2index.contains(s[j]))
        {
            char2index.insert({s[j], j});
            j++;
            current_len++;
        }
        max_len = current_len > max_len ? current_len : max_len;
        if (j == s.size())
        {
            return max_len;
        }
        else
        {
            int same_first = char2index[s[j]];
            while (i <= same_first)
            {
                char2index.erase(s[i]);
                i++;
                current_len--;
            }
            // i--;
            goto label1;
        }
        
        // return 0;
        

    // label2:
    //     return max_len;
        
    }
};