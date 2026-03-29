class Solution {
    fun isAnagram(s: String, t: String): Boolean {
        val newS = s.toCharArray().sorted().joinToString("")
        val newT = t.toCharArray().sorted().joinToString("")
        return newS.equals(newT)
    }
}
