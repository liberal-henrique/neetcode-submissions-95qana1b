class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j = 0;
        int i = 0;
        int newLength = m + n;
        while(i < nums1.size()) {
            if((n > 0 && j < nums2.size() && nums2[j] < nums1[i]) || j < nums2.size() && m <= 0) {
                nums1.insert(nums1.begin() + i, nums2[j]);
                j++;
                n--;
            } else
                m--;
            i++;
        }
        if(newLength < nums1.size()) {
            nums1.erase(nums1.begin() + newLength, nums1.end());
        }
    }
};