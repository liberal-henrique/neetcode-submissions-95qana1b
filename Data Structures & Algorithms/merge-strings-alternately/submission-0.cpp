#include <string>
using namespace std;

class Solution {

public:
    string mergeAlternately(string word1, string word2) {
        int index1 = 0;
        int index2 = 0;
        int indexResult = word1.size() + word2.size();
        int counter = 0;
        string result(indexResult, ' '); 

        while(counter < indexResult) {
            if (word1[index1]) {
                result[counter] = word1[index1];
                index1++;
                counter++;
            }

            if (word2[index2]) {
                result[counter] = word2[index2];
                index2++;
                counter++;
            }
        }
        return result;
    }
};