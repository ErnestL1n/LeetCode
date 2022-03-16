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