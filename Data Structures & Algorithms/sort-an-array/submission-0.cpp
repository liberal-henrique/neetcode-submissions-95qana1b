#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

class Solution {
public:
    vector<int> combineSortingArrays(const vector<int>& firstHalf, const vector<int>& secondHalf) {
        size_t counter = firstHalf.size() + secondHalf.size();
        vector<int> result(counter);
        size_t f = 0;
        size_t s = 0;
        size_t limiter = static_cast<int>(counter);

        for (size_t i = 0; i < limiter; i++) {
            if (((f < firstHalf.size() && firstHalf[f] <= secondHalf[s]) || s == secondHalf.size()) ) {
                result[i] = firstHalf[f];
                f++;
            } else if ((s < secondHalf.size() && secondHalf[s] < firstHalf[f]) || f == firstHalf.size()) {
                result[i] = secondHalf[s];
                s++;
            }
        }

        return result;
    }

    void getHalves(vector<int> &nums) {
        if (nums.size() <= 2) {
            if (nums.size() == 2 && nums[0] > nums[1]) 
                swap(nums[0], nums[1]);
            return ;
        }

        vector<int> firstHalf (nums.begin(), nums.begin() + (nums.size()/2));
        getHalves(firstHalf);

        vector<int> secondHalf (nums.begin() + (nums.size()/2), nums.end());
        getHalves(secondHalf);

        nums = combineSortingArrays(firstHalf, secondHalf);
    }
    vector<int> sortArray(vector<int>& nums) {
        getHalves(nums);
        return nums;
    }
};