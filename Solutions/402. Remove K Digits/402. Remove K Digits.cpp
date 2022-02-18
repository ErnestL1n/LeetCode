class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        if(k==n){
            return "0";
        }
        stack<char> stk;
        int i=0;
        while(i<n){
            while(k>0 and stk.size() and stk.top()>num[i]){
                stk.pop();
                --k;
            }
            stk.push(num[i]);
            ++i;
        }
        while(k>0){
            stk.pop();
            --k;
        }
        string res="";
        while(stk.size()){
            auto x=stk.top();stk.pop();
            res+=x;
        }
        while(res.size()>1 and res.back()=='0'){
            res.pop_back();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};