## [Reference](https://leetcode.com/problems/unique-number-of-occurrences/discuss/392840/C%2B%2B-2-approaches)
```cpp
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> m;
        unordered_set<int> s;
        for(int a:arr)
            ++m[a];
        for(auto& p:m)
            if(!s.insert(p.second).second)   //here
                return false;
        return true;
    }
};
```

### [unordered_set.insert](https://www.cplusplus.com/reference/unordered_set/unordered_set/insert/) "here"
  * returns a pair: (first) pointer to the inserted element, and (second) a boolean - false if an element was already in the set, and true otherwise. So, as we inserting occurances, we return false if we find a duplicate.
