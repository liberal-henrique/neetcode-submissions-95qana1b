class Solution {
public:
    bool isAlphaNum(char c) {
        if((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            return true;
        return false;
    }
    bool isPalindrome(string s) {
        vector<char> myWord;
        for(int i = 0; i < s.size(); i++) {
            if (isAlphaNum(s[i])) {
                if(s[i] >= 'A' && s[i] <= 'Z')
                    s[i] = s[i] + 32;
                myWord.push_back(s[i]);
            }
        }
        
        int i = 0;
        int j = myWord.size() - 1;
        while (i < j) {
            if(myWord[i] != myWord[j])
                return false;
            j--;
            i++;
        }
        return true;
    }
};
