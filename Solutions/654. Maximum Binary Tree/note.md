# credit to https://leetcode.com/votrubac/
could use binary search (as your stack is naturally sorted) instead of popping elements one by one. When you find a larger element, you can use vector.resize() to quickly remove all smaller elements. rbegin() and rend() can simplify the logic a bit, as the stack will be sorted in the descending order.


## Here is the note of some ```std::functions```

1. ```rbegin() 、 rend()```
  ![](https://www.alphacodingskills.com/cpp/img/cpp-rbegin-rend.PNG)
2. ```auto it=upper_bound(rbegin(),rend(),new TreeNode(val),[](const TreeNode* a,const TreeNode* b){return a->val<b->val;});```
    * iterator "it" is the "reverse iterator" due to the simple logic rbegin() and rend()
    * return ```a->val<b->val``` means the vector is sorted in descending order
3. next(iterator,move):moves default one step base on the iterator "direction",which means it may be reversed
4. distance(first iterator,last iterator):number of elements between first iterator(inclusive) and last element(exclusive)

## and some ```vector::functions```
1. resize(number of element from index 0(inclusive))

 
