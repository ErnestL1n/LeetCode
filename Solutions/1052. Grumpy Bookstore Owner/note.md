## [Key Idea](https://leetcode.com/problems/grumpy-bookstore-owner/discuss/299237/C%2B%2B-Sliding-Window)

  * When the owner is not grumpy, we count all customers as satisfied.

  * We then use the ```sliding window``` to count additionally satisfied customers (```add_satisfied```) if the owner start 'behaving' at minute ```i```. We track the maximum additional satisfied customers in ````m_add_satisfied```.

  * Finally, return ```satisfied + m_add_satisfied``` as the result.

  * ```cpp
    if(i>=X)
      add_satisfied-=grum[i-X]?cs[i-X]:0;
    ```
    ```
    |====| is the sliding window(which is add_satisfied, the range we can add) , we should minus from the add_satisfied if outside
    
    
    
    ............|====|
    ..............|====|
    ................|====|
    ..................|====|
    ....................|====|
    ......................|====|
    customers = [1,0,1,2,1,1,7,5]
    ```
