class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) return ;

        int index_m = m - 1;    
        int index_n = n - 1;

        for (int i = m + n - 1; i >= 0; --i) {
            if (index_n < 0) break;

            if (index_m < 0) {
                nums1[i] = nums2[index_n];
                index_n--;
            } else if (nums1[index_m] > nums2[index_n]) {
                nums1[i] = nums1[index_m];
                index_m--;
            } else {
                nums1[i] = nums2[index_n];
                index_n--;
            }
        }
    }
};