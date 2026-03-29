#include <iostream>
class Solution {
public:
    bool isPalindrome(string s) {
        int endS = s.size() - 1;
        vector<char> n(s.size());
        int pos = 0;
        for (int i = 0; i < s.size(); i++) {
            if (isalnum(s[i])) {
                n[pos] = (char)tolower(s[i]);
                pos++;
            }
        }
        
        int right = 0;
        int left = pos - 1;
        
        for(int i = 0; i < pos/2; i++) {
            if (n[right] != n[left]) {
                return false;
            }
            right++;
            left--;
        }
        return true;
    }
};
