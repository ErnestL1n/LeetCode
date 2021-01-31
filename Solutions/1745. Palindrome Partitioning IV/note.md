## [Approach](https://leetcode.com/problems/palindrome-partitioning-iv/discuss/1043100/C%2B%2B-Brute-Force-(550-ms)-and-Tabulation-(70-ms))
  * BF
    * A brute-force solution is cubic, so, with 2000 as a limit and an efficient check (avoid modifying/copying the string) it should pass.
    * take ```reference(&)``` on string ```=>``` (avoid modifying/copying the string)
  * DP (Precompute)
    *  a DP solution will be quadratic to fill ```isPal[i][j]``` tabulation
