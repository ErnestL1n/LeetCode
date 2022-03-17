class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> stk;
        int cur=0;
        for(auto& c:s){
            if(c=='('){
                stk.push(cur);
                cur=0;
            }else{
                cur+=stk.top()+max(cur,1);
                stk.pop();
            }
        }
        return cur;
    }
};