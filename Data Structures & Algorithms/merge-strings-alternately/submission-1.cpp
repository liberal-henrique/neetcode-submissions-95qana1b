#include <string>
using namespace std;

class Solution {

public:
    string mergeAlternately(string word1, string word2) {
        int index1 = 0;
        int index2 = 0;
        //int indexResult = word1.size() + word2.size();
        int counter = 0;
        string result(word1.size() + word2.size(), ' '); 

        while(counter < word1.size() + word2.size()) {
            if (word1[index1]) result[counter++] = word1[index1++];
            if (word2[index2]) result[counter++] = word2[index2++];
        }
        return result;
    }
};