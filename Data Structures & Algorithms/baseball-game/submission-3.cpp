#include <bits/stdc++.h>
#include <stdlib.h> 
using namespace std;

class Solution {
public:


    int calPoints(vector<string>& operations) {
        int result = 0;
        vector<int> myArray = {};
        for (size_t i = 0; i < operations.size(); i++) {
            if (operations[i] == "C") {
                myArray.pop_back();
            } else if (operations[i] == "+") {
                myArray.push_back(myArray[myArray.size() - 1] + myArray[myArray.size() - 2]);
            } else if (operations[i] == "D") {
                myArray.push_back(myArray[myArray.size() - 1] * 2);
            } else {
                myArray.push_back(stoi(operations[i]));
            }
        }
        for (int num : myArray) {
            result = result + num;
        }
        return result;
    }
};