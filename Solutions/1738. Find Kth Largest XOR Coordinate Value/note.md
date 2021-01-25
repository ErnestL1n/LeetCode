## [Note@credit to rock](https://leetcode.com/problems/find-kth-largest-xor-coordinate-value/discuss/1032071/JavaPython-3-Similar-to-Matrix-Block-Sum-w-diagram-analysis-and-similar-problem-list..)
```
  1. ans[r + 1][c + 1] corresponds to cell (r, c);
  2. ans[0][c] and ans[r][0] are all dummy values, which are used for the convenience of computation of DP state transmission formula.
  To calculate ans, the ideas are as below

+-----+-+-------+     +--------+-----+     +-----+---------+     +-----+--------+
|     | |       |     |        |     |     |     |         |     |     |        |
|     | |       |     |        |     |     |     |         |     |     |        |
+-----+-+       |     +--------+     |     |     |         |     +-----+        |
|     | |       |  =  |              |  ^  |     |         |  ^  |              | ^ mat[r][c]
+-----+-+       |     |              |     +-----+         |     |              |
|               |     |              |     |               |     |              |
|               |     |              |     |               |     |              |
+---------------+     +--------------+     +---------------+     +--------------+

ans[r+1][c+1] =  ans[r][c+1] ^ ans[r+1][c]    ^   ans[r][c]   ^ mat[r][c]
```
