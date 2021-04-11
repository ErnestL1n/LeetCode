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

class Solution {
public:
    int balancedStringSplit(string s) {
        int res=0,lcnt=0,rcnt=0;
        for(int i=0;i<s.size();++i){
            if(s[i]=='R')
                ++rcnt;
            else if(s[i]=='L')
                ++lcnt;
            if(rcnt!=0 and rcnt==lcnt)
                ++res;
        }
        return res;
    }
};