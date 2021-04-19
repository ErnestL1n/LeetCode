## [Optimize version with sort](https://leetcode.com/problems/queries-on-number-of-points-inside-a-circle/discuss/1165522/C%2B%2B-Brute-Force-vs.-Sort)
* Sort
  * We can improve our runtime if we sort points by x coordinate. That way, we only process points in ```[qx - r, qx + r]``` interval. We use binary search to find the start of that interval.
  * Note that we need to fiddle with data structures here to make it fast. Sorting vector of vectors, or using multiset adds noticeable overhead.
