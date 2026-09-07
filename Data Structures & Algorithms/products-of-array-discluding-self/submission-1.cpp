class Solution {
public:

    vector<int> productExceptSelf(vector<int>& nums) {
        queue<int> zeroPositions;
        int productTotal = 1;
        int pos = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0)
                zeroPositions.push(i);
            else 
                productTotal *= nums[i];
        }
        for(int i = 0; i < nums.size(); i++) {
            if(zeroPositions.empty()) {
                nums[i] = productTotal / nums[i];
            } else {
                pos = zeroPositions.front();
                if (i == pos && (zeroPositions.size() < 2))
                    nums[i] = productTotal;
                else
                    nums[i] = 0;
            }
        }
        return nums;
    }
};
