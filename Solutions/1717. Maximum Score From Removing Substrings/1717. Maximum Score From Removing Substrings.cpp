class Solution {
public:
    string foo(string s,int val,char a,char b,int& res){
        string st;
        for(char c:s){
            if(!st.empty()&&st.back()==a&&c==b){
                res+=val;
                st.pop_back();
            }else
                st.push_back(c);
        }
        return st;
    }
    int maximumGain(string s, int x, int y) {
        int res=0;
        char a='a',b='b';
        if(x<y){
            swap(x,y),swap(a,b);
        }
        foo(foo(s,x,a,b,res),y,b,a,res);
        return res;
    }
};