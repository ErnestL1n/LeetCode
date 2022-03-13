class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(int i=0;i<s.size();++i){
            if(s[i]=='[' or s[i]=='(' or s[i]=='{'){
                stk.push(s[i]);
            }else{
                if(stk.size()==0){
                    return false;
                }
                if(s[i]==']' and stk.top()!='['){
                    return false;
                }
                if(s[i]=='}' and stk.top()!='{'){
                    return false;
                }
                if(s[i]==')' and stk.top()!='('){
                    return false;
                }
                stk.pop();
            }
        }
        return stk.size()?false:true;
    }
};