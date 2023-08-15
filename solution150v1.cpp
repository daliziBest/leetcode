//reverse polish notation : https://web.stanford.edu/class/archive/cs/cs106b/cs106b.1226/lectures/05-stack-queue/slides
//use stack to solve it !
//string to integer : https://en.cppreference.com/w/cpp/string/basic_string/stol
//integer to string : https://en.cppreference.com/w/cpp/string/basic_string/to_string

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> temp;
        
        int operand1;
        int operand2;
        for (auto a : tokens) {
            if (a == "+") {
                operand2 = temp.top();
                temp.pop();
                operand1 = temp.top();
                temp.pop();
                temp.push(operand1 + operand2);
            } else if (a == "-") {
                operand2 = temp.top();
                temp.pop();
                operand1 = temp.top();
                temp.pop();
                temp.push(operand1 - operand2);
            } else if (a == "*") {
                operand2 = temp.top();
                temp.pop();
                operand1 = temp.top();
                temp.pop();
                temp.push(operand1 * operand2);
            } else if (a == "/") {
                operand2 = temp.top();
                temp.pop();
                operand1 = temp.top();
                temp.pop();
                temp.push(operand1 / operand2);
            } else {
                temp.push(stoi(a));
            }
        }

        return temp.top();
    }
};