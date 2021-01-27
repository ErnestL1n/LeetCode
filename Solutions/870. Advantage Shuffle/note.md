## [Note](https://leetcode.com/problems/advantage-shuffle/discuss/149831/C%2B%2B-6-lines-greedy-O(n-log-n))
  * For each ```B[i]```, we select the smallest number in A that is greater than ```B[i]```. If there are no such number, we select the smalest number in A.
  * Using multiset to sort and keep track of numbers in A. After a number is selected, we need to remove it from the multiset (erase by iterator takes a constant time).
  
### [set vs unordered_set in C++ STL](https://www.geeksforgeeks.org/set-vs-unordered_set-c-stl/)

```
                |     set             | unordered_set
---------------------------------------------------------
Ordering        | increasing  order   | no ordering
                | (by default)        |

Implementation  | Self balancing BST  | Hash Table
                | like Red-Black Tree |  

search time     | log(n)              | O(1) -> Average 
                |                     | O(n) -> Worst Case

Insertion time  | log(n) + Rebalance  | Same as search
                      
Deletion time   | log(n) + Rebalance  | Same as search
```

### [std::set::erase](https://www.cplusplus.com/reference/set/set/erase/#:~:text=std%3A%3Aset%3A%3Aerase&text=Removes%20from%20the%20set%20container,elements%20removed%2C%20which%20are%20destroyed.)
### [std::set::upper_bound](https://www.cplusplus.com/reference/set/set/upper_bound/)
  * Q: Why ```s.upper_bound(B[i])"``` is faster than ```"upper_bound(s.begin(), s.end(),B[i])"```
  * [A](https://leetcode.com/problems/advantage-shuffle/discuss/149831/C%2B%2B-6-lines-greedy-O(n-log-n)):Set is BST internally, and it's algorithm designed/optimized for that. Generic binary search just works with ranges, which is slow for BST.
