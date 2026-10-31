#include <iostream>
using namespace std;


class Solution {
public:
    long long combination(int elements1, int elements2) {
        int window = elements2 + elements1;
        int k = min(elements1, elements2);
        long long result = 1;
        for(int i = 1; i <= k; i++) {
            result = result * (window - i + 1) / i;
        }
        return result;
    }

    int permutationOptions(int n, int elements1, int elements2) {
        if(elements1 < 0)
            return 0;
        int result = combination(elements1, elements2);
        return result + permutationOptions(n, elements1 - 2, ++elements2);
    }

    int climbStairs(int n) {
        if(n == 1 || n == 2)
            return n;
        return permutationOptions(n, n, 0);
    }
};
