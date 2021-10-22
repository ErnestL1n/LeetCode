class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        foo(res,"",0,0,n);
        return res;
    }
    void foo(vector<string>& res,string tmp,int open,int close,int m_ax){
        if(tmp.size()==m_ax*2){
            res.push_back(tmp);
            return;
        }
        if(open<m_ax){
            foo(res,tmp+'(',open+1,close,m_ax);
        }
        if(close<open){
            foo(res,tmp+')',open,close+1,m_ax);
        }
    }
};