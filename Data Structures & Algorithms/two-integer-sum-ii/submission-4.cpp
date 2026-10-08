class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        int size = numbers.size();
        int left = 0;
        int right = size - 1;

        while (left < right && numbers[left] + numbers[right] != target) {
            if (numbers[left] + numbers[right] > target)
                right = right - 1;
            else 
                left = left + 1;
        }
        if (left >= right)
            return result;
        result.push_back(left + 1);
        if (right != size)
            right += 1; 
        result.push_back(right);
        return result;
    }
};
