#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int num2 = s.top();
                s.pop();
                int num1 = s.top();
                s.pop();
                int result;
                if (tokens[i] == "+") {
                    result = num1 + num2;
                } else if (tokens[i] == "-") {
                    result = num1 - num2;
                } else if (tokens[i] == "*") {
                    result = num1 * num2;
                } else {
                    result = num1 / num2;
                }
                s.push(result);
            } else {
                s.push(stoi(tokens[i])); 
            }
        }

        return s.top();
    }
};
