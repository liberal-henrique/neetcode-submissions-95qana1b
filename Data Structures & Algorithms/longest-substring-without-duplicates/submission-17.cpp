class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string v;
        size_t x = 0;
        size_t length = 0;
        int biggestSize = 0;
        int j = 0;
        for(int i = 0; i < s.size(); i++) {
            x = v.find(s[i]);
            if(x != string::npos) {
                j = i;
                length = v.length();
                if(biggestSize < length)
                    biggestSize = length;
                j -= (length - (x + 1));
                v.clear();
                while(j < i) {
                    v.push_back(s[j]);
                    j++;
                }
            }
            v.push_back(s[i]);
        }
        int currString = v.size();
        if(biggestSize < currString)
            return currString;
        return biggestSize;
    }
};
