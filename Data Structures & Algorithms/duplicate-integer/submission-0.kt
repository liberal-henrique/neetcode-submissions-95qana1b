class Solution {
    fun hasDuplicate(nums: IntArray): Boolean {
        var result = false
        for(i in 0 until nums.size) {
            var case = nums[i]
            for (n in i + 1 until nums.size) {
                if (case == nums[n]) result = true
            }
        }
        return result
    }
}
