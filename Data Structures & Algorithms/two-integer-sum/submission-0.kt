class Solution {
    fun twoSum(nums: IntArray, target: Int): IntArray {
        var itemI = 0
        var itemJ = 0
        for (i in nums.indices) {
            for (j in i + 1 until nums.size) {
                if (nums[i] + nums[j] == target) {
                    itemI = i
                    itemJ = j
                    return intArrayOf(itemI, itemJ)
                }
            }
        }
        return intArrayOf(itemI, itemJ)
    }
}
