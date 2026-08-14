class Solution {
public:
    bool isValid(string s) {
    map<char, char> expectedComb = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
    unordered_set<char> openingBrackets = {'(', '{', '['};
    stack<char> st;

    for (char c : s) {
        if (openingBrackets.find(c) != openingBrackets.end()) {
            st.push(c);
        } else {
            if (!st.empty() && expectedComb.at(st.top()) == c) {
                st.pop();
            } else {
                return false;
            }
        }
    }
    if (st.empty())
        return true;
    return false;
}
};
