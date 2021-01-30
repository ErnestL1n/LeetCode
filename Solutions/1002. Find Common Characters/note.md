## [Idea](https://leetcode.com/problems/find-common-characters/discuss/247573/C%2B%2B-O(n)-or-O(1)-two-vectors)
  * For each string, we count characters in ```cnt1```. Then, we track the minimum count for each character in ```cnt```.
  * Complexity Analysis
    * Runtime: ```O(n)```, where n is the total number of characters.
      Memory: ```O(1)``` (we use two fixed-size vectors).
      
## C++
  * int to string alphabet
    ```string(1,'a'+i)    // i=0~25 ``` 
    
## Java
  * int to string alphabet
    ```""+(char)(i+'a')   // i=0~25 ``` 
