## [Trick](https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/discuss/1064548/JavaC%2B%2BPython-Binary-Search)


### Explanation
Binary search the size of bag,
which is called penalty in this problem.

For each penalty value, we split the balls into bags with this value.
For example, the ```mid = 3```,
```A[i] = 2```, we split it into ```[2]```, and operations = 0
```A[i] = 3```, we split it into ```[3]```, and operations = 0
```A[i] = 4```, we split it into ```[3,1]```, and operations = 1
```A[i] = 5```, we split it into ```[3,2]```, and operations = 1
```A[i] = 6```, we split it into ```[3,3]```, and operations = 1
```A[i] = 7```, we split it into ```[3,3,1]```, and operations = 2

The number of operation we need is ```(a - 1) / mid```

If the total operation > max operations,
the size of bag is too small,
we set ```left = mid + 1```

Otherwise,
this size of bag is big enough,
we set right = mid

We return the final result,
where result = left = right.


### Complexity
Time ```O(nlog10^9)```

Space ```O(1)```
