## [Two Solutions, in-order traversal and a more general way using TreeSet](https://leetcode.com/problems/minimum-absolute-difference-in-bst/discuss/99905/Two-Solutions-in-order-traversal-and-a-more-general-way-using-TreeSet)
  1.
   * The most common idea is to first inOrder traverse the tree and compare the delta between each of the adjacent values. It's guaranteed to have the correct answer because it is a BST thus inOrder traversal values are sorted.
   * Solution 1 - In-Order traverse, time complexity O(N), space complexity O(1).
  2.
   * What if it is not a BST? (Follow up of the problem) The idea is to put values in a TreeSet and then every time we can use O(lgN) time to lookup for the nearest values.
   * Solution 2 - Pre-Order traverse, time complexity O(NlgN), space complexity O(N).

## [Is there a TreeSet data structure equivalent in C++ with similar functions](https://stackoverflow.com/questions/50078250/is-there-a-treeset-data-structure-equivalent-in-c-with-similar-functions)
  * See third answer
