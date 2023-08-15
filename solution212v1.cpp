//有几个容易犯的语法错误已经在代码里标注
//1内部类的成员变量定义private外部类无法直接访问
//2内部类的使用

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        //Trie wordCollection(); //error!
        //Trie wordCollection = new Trie(); //error! new返回的是指针或者地址
        Trie* wordCollection = new Trie();
        for (auto s : words) {
            (*wordCollection).insert(s);
        }

        unordered_set<string> resultHash;
        int m = board.size();
        int n = board[0].size();
        string s = "";
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                myFindWords(board, i, j, resultHash, s, wordCollection);
            }
        }

        vector<string> result(resultHash.begin(), resultHash.end());
        return result;
    }

private:
    //私有类
    class Trie {
    public:
        Trie() {
            pointerAlphabet.assign(26, nullptr);
            isEnd = false;
        }
        
        void insert(string word) {
            Trie* child = this;
            for (auto c : word) {
                if ((*child).pointerAlphabet[c - 'a'] == nullptr) {
                    (*child).pointerAlphabet[c - 'a'] = new Trie();
                    child = (*child).pointerAlphabet[c - 'a'];
                } else {
                    child = (*child).pointerAlphabet[c - 'a'];
                }
            }

            (*child).isEnd = true;
        }

    //private: //error!!!
        vector<Trie*> pointerAlphabet;
        bool isEnd;
    };


    //(i,j)一定没被访问过
    void myFindWords(vector<vector<char>>& board, int i, int j, unordered_set<string>& resultHash, string& beforeString, Trie* indicator) {
        //base case
        //不存在该前缀
        char currentChar = board[i][j];
        if ((*indicator).pointerAlphabet[currentChar - 'a'] == nullptr) {
            return;
        }

        //存在前缀
        indicator = (*indicator).pointerAlphabet[currentChar - 'a'];
        beforeString.push_back(currentChar);
        if ((*indicator).isEnd) {
            resultHash.insert(beforeString);
        }
        
        int m = board.size();
        int n = board[0].size();
        board[i][j] = '.';
        if (i - 1 >= 0 && board[i - 1][j] != '.') {
            myFindWords(board, i - 1, j, resultHash, beforeString, indicator);
        }
        if (i + 1 < m && board[i + 1][j] != '.') {
            myFindWords(board, i + 1, j, resultHash, beforeString, indicator);
        }
        if (j - 1 >= 0 && board[i][j - 1] != '.') {
            myFindWords(board, i, j - 1, resultHash, beforeString, indicator);
        }
        if (j + 1 < n && board[i][j + 1] != '.') {
            myFindWords(board, i, j + 1, resultHash, beforeString, indicator);
        }

        board[i][j] = currentChar;
        beforeString.pop_back();
        return;
    }
};