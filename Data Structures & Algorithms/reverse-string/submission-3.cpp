class Solution {
public:
    void reverseString(vector<char>& s) {
        int endS = s.size() - 1;

        if (s.size() < 2) return;
        for(int i = 0; i < s.size()/2; i++) {
            std::swap(s[i], s[endS]);
            endS--;
        }
    }
};