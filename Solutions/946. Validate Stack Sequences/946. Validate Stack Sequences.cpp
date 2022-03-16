// stack time: O(N),space: O(N)
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int i=0;
        for(auto& p:pushed){
            stk.push(p);
            while(stk.size() and stk.top()==popped[i]){
                stk.pop();
                ++i;
            }
        }
        return stk.size()==0;
    }
};

// use original array: time: O(N),space: O(1)
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i=0,j=0;
        for(auto& p:pushed){
            pushed[i++]=p;
            while(i>0 and pushed[i-1]==popped[j]){
                --i,++j;
            }
        }
        return i==0;
    }
};