class Solution {
public:
    void reverseString(vector<char>& s) {
        int size = s.size();
        int endS = size - 1;

        if (size < 2) return;
        for(int i = 0; i < size/2; i++) {
            char tmp = s[i];
            s[i] = s[endS];
            s[endS] = tmp;
            endS--;
        }
    }
};