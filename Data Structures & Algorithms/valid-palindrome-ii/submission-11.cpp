class Solution {

public:
    bool skipLetter(string s, int right, int left) {
    while (right < left) {
        if(s[right] != s[left]) return false;
            right++;
            left--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int right = 0;
        int left = s.size() - 1;

        while (right < left) {
            if (s[right] != s[left]) {
                bool resultLeft = skipLetter(s, right, left - 1);
                bool resultRight = skipLetter(s, right + 1, left);
                if(!resultLeft && !resultRight)
                    return false;
                else
                    return true;
            }
            right++;
            left --;
        }
        return true;
    }
};

//true + true -> true
//false + true -> true
//true + false -> true
//false + false -> false 


