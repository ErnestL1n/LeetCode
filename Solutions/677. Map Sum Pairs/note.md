## [Explanation](https://leetcode.com/problems/map-sum-pairs/discuss/107554/C%2B%2B-O(1)-9-lines-Trie-%2B-Hash-map)
  Hash map is to locate existing values, and trie is store the prefixes sum. Technically, the runtime complexity is affected by the size of individual strings, but here we can say O(1) as the string size is limited to 100.
  
  
## Pass i,j = P i,j = Insert operation i,j
* where i=each insertion in one test case
* j=each character in insertion paremeter string "prefix"
* P i,1=entry point(root) always don't do sum operation
![image](https://user-images.githubusercontent.com/52807284/128299844-a9a1f95f-3b40-4e63-a149-c24e959c7ebb.png)

