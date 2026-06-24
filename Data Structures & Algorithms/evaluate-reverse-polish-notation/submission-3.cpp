#include <stack>
using namespace std;

class Solution {
    public:
        int operation(stack<int> &res, char c) {
            int value = res.top();
            res.pop();
            int result = res.top();
            res.pop();
            switch(c) {
                case '+': 
                    result += value;
                    break;
                case '-': 
                    result -= value;
                    break;
                case '*': 
                    result *= value;
                    break;
                case '/':
                    result /= value;
                    break;
                default:
                    break;
            }
            return result;
        }

        int evalRPN(vector<string>& tokens) {
            stack<int> result;
            for (string str : tokens) {
                if (str.size() > 1 || (str[0] >= '0' && str[0] <= '9'))
                    result.push(stoi(str.c_str()));
                else if (str[0] == '+')
                    result.push(operation(result, '+'));
                else if (str[0] == '-')
                    result.push(operation(result, '-'));
                else if (str[0] == '*')
                    result.push(operation(result, '*'));
                else if (str[0] == '/') 
                    result.push(operation(result, '/'));
            }
            int answer = 0;
            answer = result.top();

            return answer;
        }
};
