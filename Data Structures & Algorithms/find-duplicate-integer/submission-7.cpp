class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int>::iterator fast = nums.begin();
        vector<int>::iterator slow = nums.begin();
        while (1) {
            fast = nums.begin() + *fast;
            fast = nums.begin() + *fast;
            slow = nums.begin() + *slow;
            if (fast == slow)
                break;
        }
        slow = nums.begin();
        while (1) {
            fast = nums.begin() + *fast;
            slow = nums.begin() + *slow;
            if (fast == slow)
                break;
        }
        int distance = slow - nums.begin();
        return distance;
    }
};
