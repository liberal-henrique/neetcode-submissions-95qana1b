class Solution {

    bool skipLetter(string s, int right, int left) {
        while (right <= s.size()/2) {
            if(s[right] != s[left]) return false;
            right++;
            left--;
        }
        return true;
    }

public:
    bool validPalindrome(string s) {
        int right = 0;
        int size = s.size();
        int left = size - 1;
        int newLeft = 0;
        int newRight = 0;

        if (size <= 2) return true;
        
        while (right <= s.size()/2) {
            if (s[right] != s[left]) {
                newLeft = left;
                newRight = right;
                bool resultLeft = skipLetter(s, newRight, --newLeft);
                newLeft = left;
                newRight = right;
                bool resultRight = skipLetter(s, ++newRight, newLeft);
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


