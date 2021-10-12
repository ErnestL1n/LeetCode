/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        unsigned l=1,r=n,picked;
        while(l<=r){
            picked=(l+r)/2;
            if(guess(picked)==0)
                return picked;
            else if(guess(picked)==1)
                l=picked+1;
            else
                r=picked-1;
        }
        return 1e9+7;
    }
};