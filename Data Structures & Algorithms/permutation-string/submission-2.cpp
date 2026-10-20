class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> mp;
        for(char c: s1) {
            auto it = mp.find(c);
            if(it == mp.end()) 
                mp.insert({c, 1});
            else
                it->second++; 
        }
        int sizeS1 = s1.size();
        int sizeS2 = s2.size();
        int x = 0;
        bool result = false;
        auto mpCopy = mp;
        for(int i = 0; i < sizeS2; i++){
            auto it = mpCopy.find(s2[i]);
            if(it != mpCopy.end()) {
                x = i;
                sizeS1 = s1.size();
                while(sizeS1 > 0 && x < sizeS2) {
                    auto it = mpCopy.find(s2[x]);
                    if(mpCopy.contains(s2[x])) {
                        it->second--;
                        if(it->second < 0)
                            break;
                    } else
                        break;
                    x++;
                    sizeS1--;
                }
                if(sizeS1 == 0) {
                    return true;
                }
                mpCopy = mp;
            }
        }
        return result;
    }
};
