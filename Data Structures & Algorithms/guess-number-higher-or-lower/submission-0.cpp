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
    int searchGuessNumber(int left, int right) {
        int mid = left + (right - left) / 2;

        int evaluation = guess(mid);

        if (evaluation == 0)
            return mid;
        if (evaluation > 0) {
            return searchGuessNumber(mid + 1, right);
        } else 
            return searchGuessNumber(left, mid - 1);
    }

    int guessNumber(int n) {
        return searchGuessNumber(1, n);
    }
};