class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size(),res=0;
        stack<int> stk;
        for(int i=0;i<n;++i){
            if(s[i]=='('){
                stk.push(i);
            }else{
                if(stk.size()){
                    if(s[stk.top()]=='('){
                        stk.pop();
                    }else{
                        stk.push(i);
                    }
                }else{
                    stk.push(i);
                }
            }
        }
        if(stk.size()==0){
            res=n;
        }else{
            int x=n,y=0;
            while(stk.size()){
                y=stk.top();stk.pop();
                res=max(res,x-y-1);
                x=y;
            }
            res=max(res,x);
        }
        return res;
    }
};