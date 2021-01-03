## Reference: [C++ Union-Find Both/One](https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/discuss/831536/C%2B%2B-Union-Find-BothOne)


### Intuition
We would use union-find to solve this problem for one person. For two (or more) people, we first populate our "shared" disjoined set, using type 3 edges.

Then, we process Alice and Bob independently, using the "shared" disjoined set as a starting point.

Every time we find a non-redundant edge, we increment used. We also check that the graph is fully connected for each person.

In the end, we can remove total - used edges.

### Complexity Analysis

Time: O(m), where m is the number of edges. We go through all edges 3 times. The complexity of the find operation is O(𝛼(n)) as we use both rank and path compression. 𝛼(n) can be considered a constant for all practical purposes.
Memory: O(n) for a disjoined set.


### Is it redundant to operate ```swap(i,j),if (ds[j]<ds[i])``` ?

  A: We use a rank (group size) to merge smaller a group into a larger one to improve the performance.

However , I still think it is not necessary in this case
