## [credit to rock](https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/discuss/969535/JavaPython-3-Prefix-Sum-O(n)-code-w-brief-explanation-and-analysis.)

```latex
res[i] = (nums[i] - nums[0]) + (nums[i] - nums[1]) + ... + (nums[i] - nums[i - 1])        <--- absolute difference of nums[i] with first i numbers
     +   (nums[i + 1] - nums[i]) + (nums[i + 2] - nums[i]) + ... + (nums[n - 1] - nums[i])   <--- absolute difference of nums[i] with last n - i numbers
```
after simplification:

```latex
res[i] = i * nums[i] - (nums[0] + ... + nums[i - 1])        <--- absolute difference of nums[i] with first i numbers
     + (nums[i + 1] + ... + nums[n]) - (n - i) * nums[i]   <--- absolute difference of nums[i] with last n - i numbers
```
that is:
```latex
res[i] = i * nums[i] - prefixSum[i]
prefixSum[n] - prefixSum[i] - (n - i) * nums[i]
```

## usual definition of prefix[i]

```cpp
prefix[0]=0
prefix[1]=nums[0]+prefix[0]
prefix[2]=nums[1]+prefix[1]
.
..
...
```
