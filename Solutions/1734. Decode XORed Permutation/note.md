## [XOR](https://leetcode.com/lenchen1112/)
  1. Original list is```[a1, a2, a3, a4, a5]```, which means encoded list is ```[a1^a2, a2^a3, a3^a4, a4^a5]```
  2. We can get ```a1^a2, a1^a3, a1^a4, a1^a5``` after iterating encoded list.
  3. And we can compute ```a1^a2^a3^a4^a5``` beforehand.
  4. Then by xor all of them we can get the first element ```a1```: 
     * ```(a1^a2) ^ (a1^a3) ^ (a1^a4) ^ (a1^a5) ^ (a1^a2^a3^a4^a5) = a1```
