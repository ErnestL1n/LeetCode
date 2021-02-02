## [Track even sum](https://leetcode.com/problems/sum-of-even-numbers-after-queries/discuss/231098/C%2B%2B-O(n)-track-even-sum)
  * First, we calculate ```sum``` of even numbers. Then, for each query, if ```A[index]``` is even, we subtract its value from ```sum```. 
  * Then we add ```val``` to ```A[index]```. If ```A[index]``` is now even, we add its value to ```sum```.
