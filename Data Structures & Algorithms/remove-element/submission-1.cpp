class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int indexToInsert = nums.size() - 1;

        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] == val) {
                nums[i] = nums[indexToInsert];
                nums[indexToInsert] = val;
                indexToInsert--;
            }
        }

        return indexToInsert + 1;

    }
};