class Solution {
    fun getConcatenation(nums: IntArray): IntArray {
        var ans = IntArray(nums.size * 2)
        for(i in 0 until nums.size) {
            ans[i] = nums[i]
            ans[i + nums.size] = nums[i]
        }
        return ans
    }
}
