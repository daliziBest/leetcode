//熟悉string类和unordered_map类的使用
//将pattern和s直接进行匹配

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        //提取s里的所有word
        vector<string> words;
        pullwords(words, s);
        if (pattern.size() != words.size())
            return false;
        unordered_map<char, string> p2s;
        unordered_set<string> string_set;
        for (int i = 0; i < pattern.size(); i++)
        {
            auto iter = p2s.find(pattern[i]);
            if (iter != p2s.end())  //找到
            {
                if (iter->second == words[i])
                {
                    continue;
                }
                else
                {
                    return false;
                }
            }
            else   //没找到
            {
                //contains是C++20的标准,编译时需要加入-std=c++20
                if (string_set.contains(words[i]))
                {
                    return false;
                }
                else
                {
                    p2s.insert({pattern[i], words[i]});
                    string_set.insert(words[i]);
                }
            }
        }

        return true;
    }
private:
    void pullwords(vector<string> &words, string &s)
    {
        int i = 0;
        string temp;
        while (true)
        {
            temp = "";
            while (i < s.size() && s[i] != ' ')
            {
                temp.push_back(s[i++]);
            }
            words.push_back(temp);
            if (i < s.size())
            {
                i++;
                continue;
            }
            else
            {
                break;
            }
        }
        return;
    }
};