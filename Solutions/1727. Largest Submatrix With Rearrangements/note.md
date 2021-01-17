## Credit to [Rioto9858](https://leetcode.com/problems/largest-submatrix-with-rearrangements/discuss/1020682/Java-or-6ms-or-easy-understanding-with-comments-and-images)
![](https://i.imgur.com/BtA8N7h.png)

## C++
* we take ```&(reference)``` to ```matrix``` so we can't not just do it in one pass , or it might copy into new vector

### Can we just find count without iterate all rows in the final step , instead we just find it in the final row , since we add the above 1s to the final row?
* No, since the Matrix only accumulates when matrix[row][col] != 0
