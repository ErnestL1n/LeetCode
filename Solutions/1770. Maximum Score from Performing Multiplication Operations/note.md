## Idea
In this "state" ,assume we had already picked 2 elements from nums ,we can see 
  * ```1. n=2```
  * ```2. nums.size()==6  ```
  * ```3. number of elements pick from left side(leftpicked) ==1 => leftside pointer(after this state we can pick from left) in nums became 1 (which equals to leftpicked)``` 
  * ```4. number of elements pick from right side(rightpicked) ==1 => rightside pointer(after this state we can pick from right) in nums became 6-(2-1)-1=4 (nums.size()-(n-leftpicked)-1)``` 
  
![](https://i.imgur.com/oai1sCH.png)
