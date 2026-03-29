class TrieNode {
    val children = HashMap<Char, TrieNode>()
}

class Trie {
    val root = TrieNode()

    fun insert(word: String) {
        var node = root
        for (c in word) {
            if (!node.children.containsKey(c)) {
                node.children[c] = TrieNode()
            }
            node = node.children[c]!!
        }
    }

    fun lcp(word: String, prefixLen: Int): Int {
        var node = root
        var i = 0
        while (i < minOf(word.length, prefixLen)) {
            if (!node.children.containsKey(word[i])) {
                return i
            }
            node = node.children[word[i]]!!
            i++
        }
        return minOf(word.length, prefixLen)
    }
}

class Solution {
    fun longestCommonPrefix(strs: Array<String>): String {
        if (strs.size == 1) return strs[0]

        var mini = 0
        for (i in 1 until strs.size) {
            if (strs[i].length < strs[mini].length) {
                mini = i
            }
        }

        val trie = Trie()
        trie.insert(strs[mini])
        var prefixLen = strs[mini].length

        for (i in strs.indices) {
            prefixLen = trie.lcp(strs[i], prefixLen)
        }

        return strs[0].substring(0, prefixLen)
    }
}