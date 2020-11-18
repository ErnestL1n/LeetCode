From Leetcode discussion:

Q:why return low rather than high?

A:Because when high = low+1, then mid = left.
If the target > nums[mid], then low = mid +1 = high. The target position can be low or high, since they are the same.
But if the target < nums[mid], then high = mid - 1 = low. The target position must be low, not the high.
