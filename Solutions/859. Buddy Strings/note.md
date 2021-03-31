## [Idea](https://leetcode.com/problems/buddy-strings/discuss/141780/Easy-Understood)

If ```a.length() != b.length()```: no possible swap

If ```a == b```, we need swap two same characters. Check is duplicated char in ```a```.

In other cases, we find index for ```a[i] != b[i]```. There should be only 2 diffs and it's our one swap.
