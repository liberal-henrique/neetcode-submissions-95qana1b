/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    
    int highOrLower(int left, int right) {
        int attempt = (right + left) / 2;
        int result = guess(attempt);
        if (result == 0)
            return attempt;
        if (result > 0)
            return highOrLower(attempt, right);
        else
            return highOrLower(left, attempt);
    } 

    int guessNumber(int n) {
        return highOrLower(1, n);
    }
};