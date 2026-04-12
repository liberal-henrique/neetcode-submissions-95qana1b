using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 != 0 ) return false;
        unordered_set<char> openBrackets = {'(', '[', '{'};
        map<char, char> validCombination = {{'}', '{'}, {')', '('}, {']', '['}};
        stack<char> st;
        for (char element : s) {
            if (openBrackets.find(element) != openBrackets.end()) {
                st.push(element);
            } else {
                if (st.empty()) return false;
                if (st.top() == validCombination.at(element)) 
                    st.pop();
                else 
                    return false;
            }
        }
        if (!st.empty()) 
            return false;
        return true;
    }
};
