class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> stk;
        //remove @ position
        for(int i=0;i<s.size();++i){
            if(s[i]=='(')
                stk.push(i);
            if(s[i]==')'){
                if(stk.size())
                    stk.pop();
                else
                    s[i]='@';
            }
        }
        while(stk.size()){
            s[stk.top()]='@';
            stk.pop();
        }
        s.erase(remove(s.begin(),s.end(),'@'),s.end());
        return s;
    }
};