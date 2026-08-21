class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> ranking;
        for(int elem : nums) {
            auto it = ranking.find(elem);
            if (it != ranking.end()) {
                it->second += 1;
            } else {
                ranking.insert({elem, 1});
            }
        }
        vector<int> result;
        int biggest = 0;
        int saveKey = 0;
        while (k > 0) {
            biggest = 0;
            for (auto& [key, value] : ranking) {
                if (value > biggest) {
                    biggest = value;
                    saveKey = key;
                }
            }
            result.push_back(saveKey);
            ranking.erase(saveKey);
            k--;
        }
        return result;
    }
};
