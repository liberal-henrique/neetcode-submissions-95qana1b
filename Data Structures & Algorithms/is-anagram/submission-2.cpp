class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int>mp;
        for(char c: s) {
            auto it = mp.find(c);
            if(it == mp.end())
                mp.insert({c, 1});
            else
                it->second++;
        }
        for(char c: t) {
            auto it = mp.find(c);
            if(it == mp.end())
                return false;
            else
                it->second--;
        }
        for (auto const &[key, value]: mp) {
            if (value != 0) 
                return false;
        }
        return true;
    }
};
