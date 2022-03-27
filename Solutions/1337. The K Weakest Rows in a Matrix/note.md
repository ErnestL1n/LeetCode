# C++
## [Set](https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/discuss/496490/C%2B%2B-Set)
  * the set to ```{power, index}``` is sorted in the ascending order(default)
  * the set would compare the whole pair ```{power, index}```. If the power is the same, then it will compare indices
  
## [Priority_Queue](https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/discuss/549050/C%2B%2B-Heap)
  * [Priority queue of pairs in C++ with ordering by first and second element](https://www.geeksforgeeks.org/priority-queue-of-pairs-in-c-with-ordering-by-first-and-second-element/)
  * ```cpp
    //note that this is the min_priority implementation , though it takes ">" (weird...but amazing haha...)
    struct cmp{
        bool operator()(const pr& a,const pr& b){
            return a.first!=b.first?a.first>b.first:a.second>b.second;
        }
    };
    ```
  * ```cpp
    //same as above , the greater takes ">" and returns , becoming the third parameter in min_priority queue
    template <class T> struct greater : binary_function <T,T,bool> {
    bool operator() (const T& x, const T& y) const {return x>y;}
    };
    
    priority_queue<pr,vector<pr>,greater<pr>> pq
    ```
## Binary Search
### compare this two: [1552](https://github.com/ErnestL1n/LeetCode/blob/master/Solutions/1552.%20Magnetic%20Force%20Between%20Two%20Balls/1552.%20Magnetic%20Force%20Between%20Two%20Balls.cpp)、[35](https://github.com/ErnestL1n/LeetCode/blob/master/Solutions/35.%20Search%20Insert%20Position/35.%20Search%20Insert%20Position.cpp)
   * Here is to find the rightmost ```"1"``` position and plus ```1``` to get number or ```1s``` in row , since array is ```0-indexed```
   *  ```cpp
      int numOnes(vector<int>& row){
        int l=0,r=row.size()-1;
        while(l<=r){
            int m=(l+r)/2;
            if(row[m]==1)
                l=m+1;
            else
                r=m-1;
        }
        return l;
      }
      ```
# Go
[golang sort slices of slice by first element](https://stackoverflow.com/questions/55360091/golang-sort-slices-of-slice-by-first-element)
```go
import "sort"

sort.Slice(s, func(i, j int) bool {
    // edge cases
    if len(s[i]) == 0 && len(s[j]) == 0 {
        return false // two empty slices - so one is not less than other i.e. false
    }
    if len(s[i]) == 0 || len(s[j]) == 0 {
        return len(s[i]) == 0 // empty slice listed "first" (change to != 0 to put them last)
    }

    // both slices len() > 0, so can test this now:
    return s[i][0] < s[j][0]
})
```
