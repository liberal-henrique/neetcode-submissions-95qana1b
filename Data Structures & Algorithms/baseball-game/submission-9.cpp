#include <bits/stdc++.h>
#include <stdlib.h> 
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> scores = {};
        for (size_t i = 0; i < operations.size(); i++) {
            if (operations[i] == "C") {
                scores.pop_back();
            } else if (operations[i] == "+") {
                scores.push_back(scores[scores.size() - 1] + scores[scores.size() - 2]);
            } else if (operations[i] == "D") {
                scores.push_back(scores[scores.size() - 1] * 2);
            } else {
                scores.push_back(stoi(operations[i]));
            }
        }
        return accumulate(scores.begin(), scores.end(), 0);
    }
};