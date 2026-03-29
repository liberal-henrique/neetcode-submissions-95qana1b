class TrieNode {
    val children: MutableMap<Char, TrieNode> = mutableMapOf()
    var isEndOfWord: Boolean = false
}

class Trie {
	val root = TrieNode()
    
    fun insert(str: String) {
        var currentNode = root
        for(char in str) {
            currentNode = currentNode.children.getOrPut(char){ TrieNode() }
        }
        currentNode.isEndOfWord = true
    }
}

fun lcp(root: TrieNode, size: Int = 0): Int {
    if (root.isEndOfWord == true) return size
    if (root.children.size != 1) return size
    
    return lcp(root.children.values.first(), size + 1)
}

class Solution {
    fun longestCommonPrefix(strs: Array<String>): String {
        val trie = Trie()
        for (str in strs) {
            trie.insert(str)
        }

        var result: String = ""

        var size: Int = lcp(trie.root)
        if (size == 0) return result
        else return strs[0].substring(0, lcp(trie.root))
    }
}
