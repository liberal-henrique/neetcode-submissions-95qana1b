class Solution {
public:
    bool isSubsequence(string s, string t) {
        int pS = 0;
        int pT = 0;
        int sizeS = s.size();
        if(sizeS == 0)
            return true;
        
        for(; pT < t.size(); pT++) {
            if(t[pT] == s[pS]) {
                if(pS == (sizeS - 1))
                    return true;
                pS++;
            }
        }

        return false;
    }
};