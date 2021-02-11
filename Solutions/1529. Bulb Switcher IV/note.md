## [Intuition](https://leetcode.com/problems/bulb-switcher-iv/discuss/755843/C%2B%2BJava-O(n))
The order of bit operations does not matter. Go from left to right, switching bulbs greedily.

Similar question: [995. Minimum Number of K Consecutive Bit Flips](https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/). 

  * ```Algorithm```
    * Go from left to right, tracking state of the remaining bulbs. When a bulb does not match the state, we change the state and increment the result.
