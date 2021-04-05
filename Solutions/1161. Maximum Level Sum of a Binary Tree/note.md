## C++ STL
  * [```std::vector::resize```](https://www.cplusplus.com/reference/vector/vector/resize/)
  * [```std::distance```](https://www.cplusplus.com/reference/iterator/distance/)
## C++ type 
  * [```std::size_t```](https://en.cppreference.com/w/cpp/types/size_t)
 ```cpp
  public:
    vector<int> sums;
    void dfs(TreeNode* root,size_t level){
        if(root){
            sums.resize(max(sums.size(),level));
            sums[level-1]+=root->val;
            dfs(root->left,level+1);
            dfs(root->right,level+1);
        }
    }
                        
    //above code which is more clear and simple as comparing to this one:
  public:
    vector<int> sums;
    void dfs(TreeNode* root,int level){
        if(root){
            int s=sums.size();     //if we don't save sums.size() and call sums.resize(max(sums.size(),level))
                                   //=> no matching function for call to 'max'
            sums.resize(max(s,level));
            sums[level-1]+=root->val;
            dfs(root->left,level+1);
            dfs(root->right,level+1);
        }
    }
```   
## Python library
  * [Python List index()](https://www.programiz.com/python-programming/methods/list/index)        
                          
## Java 8 stream
```java
IntStream.range(0, list.size()).reduce(0, (a, b) -> list.get(a) < list.get(b) ? b : a);
```                          
