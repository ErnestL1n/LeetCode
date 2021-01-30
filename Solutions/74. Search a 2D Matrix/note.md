## [Don't treat it as a 2D matrix, just treat it as a sorted list](https://leetcode.com/problems/search-a-2d-matrix/discuss/26220/Don't-treat-it-as-a-2D-matrix-just-treat-it-as-a-sorted-list)
  * ```
    n * m matrix convert to an array => matrix[x][y] => a[x * m + y]
    an array convert to n * m matrix => a[x] =>matrix[x / m][x % m]
    ```
## Binary Search
   ### Type1 Find position with lo (larger one when breaks) indice in an array
     i.e.  35. Search Insert Position
           278. First Bad Version
     return lo which is after the break condition and we want to find "lo" insertion position
     return the answer we wanted in the while loop(quickly break)
  ### Type2 Find element with hi (smaller one when breaks) indice in an array
     i.e.  74. Search a 2D Matrix
           704. Binary Search
     return -1 or false as well after the while loop breaks
     return the answer we wanted in the while loop(quickly break)
  ### Type3 Find distance with hi (smaller one when breaks) indice but without accessing the array with "hi" indice
     i.e.  1552. Magnetic Force Between Two Balls
     return hi which is after the break condition and we want to find appropriate distance
     
