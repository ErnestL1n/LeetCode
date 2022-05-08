/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    stack<NestedInteger> stk;
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(auto it=nestedList.rbegin();it!=nestedList.rend();++it){
            stk.push(*it);
        }
    }
    
    int next() {
        auto x=stk.top();stk.pop();
        return x.getInteger();
    }
    
    bool hasNext() {
        while(stk.size()){
            auto x=stk.top();
            if(x.isInteger()){
                return true;
            }
            stk.pop();
            vector<NestedInteger> nl=x.getList();
            for(auto it=nl.rbegin();it!=nl.rend();++it){
                stk.push(*it);
            }
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */