class Solution {
    fun isAnagram(s: String, t: String): Boolean {
        if (s.length != t.length) return false
        val newS = s.toCharArray().sorted()
        val newT = t.toCharArray().sorted()
        return newS.equals(newT)
    }
}
