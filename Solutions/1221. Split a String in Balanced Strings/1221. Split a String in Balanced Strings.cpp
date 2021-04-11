class Solution {
public:
    int balancedStringSplit(string s) {
        stack<char> stk;
        int res=0;
        for(int i=0;i<s.size();++i){
            if(stk.empty() or stk.top()==s[i])
                stk.push(s[i]);
            else
                while(stk.size())
                    stk.pop(),++res,++i;
        }
        return res;
    }
};