## [Post-Order Traversal](https://leetcode.com/problems/delete-leaves-with-a-given-value/discuss/484778/C%2B%2B-Post-Order-Traversal)
  * As we need to remove a parent if it becomes a leaf, we need to process children first, then "visit" the parent (post-order traversal).

    ```cpp
    root.left == root.right == null 
    ```
     * can be simplified as
    ```cpp
    root.left == root.right 
    ```
     * since root.left == root.right then they must both be null
