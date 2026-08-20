class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        map<vector<int>, int> keyAndPosition;
        for(string elem : strs) {
            vector<int> key(26, 0);
            for(char e: elem) {
                key[int(e) - 'a'] += 1;
            }
            auto it = keyAndPosition.find(key);
            if (it != keyAndPosition.end()) {
                result[it->second].push_back(elem);
            }
            else {
                result.push_back({elem});
                keyAndPosition.insert({key, result.size() - 1});
            }
        }
        return result;
    }
};
