## [Explanation](https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/discuss/1053508/JavaC%2B%2BPython-Easy-and-Concise)
Compare all neignbour elements ```(a,b)``` in ```nums```,
the case of ```a > b``` can happen at most once.

Note that the first element and the last element are also connected.  ```A[i] > A[(i + 1) % A.size()]```

If all ```a <= b```, A is already sorted.
And if all ```a <= b``` including only one ```a > b```,
we can rotate and make ```b``` the first element.
Other case, return false.
