## Similar Ideas : [35. Search Insert Position](https://github.com/ErnestL1n/LeetCode/blob/master/Solutions/35.%20Search%20Insert%20Position/note.md)
  ```cpp
  while(lo<=hi){
            int dis=(lo+hi)/2;
            if(foo(p,dis,m))
                lo=dis+1;
            else{
                hi=dis-1;
            }
        }
        return hi;
  ```
  * when the ```while``` loop breaks , the state is : ```low=high+1``` , which the previous states are 
    1. ```low+1=high,dis=(low+high)/2 ,then low=dis+1=high``` 
    2. ```low=high,dis=low=high ,then low=dis+1 ,whereas high is still dist, thus we return high```
  * the function ```foo(vector<int>& dis,int dist,int m)``` do the thing:
    1. check if the number of balls can be placed in to baskets, under the condition that the minimum distance between any two balls is dist
    2. if dist is too small , we can put all m balls into baskets , but it might not be the answer we want , since we want to maximum d
        * we do ```low=dist+1``` to make dist bigger
    3. if dist is too large , we can't put all m balls into baskets
        * we do ```high=dist-1``` to make dist smaller

### Go :
  * sort ```arr []int``` : 
    ```sort.Ints(arr)```
    
### Python : 
  * sort ```arr : List[int]``` : 
    ```arr.sort()```
