//wrong answer 
//Line 32: Char 20: runtime error: signed integer overflow: 3469975787943862651 * 10 cannot be represented in type 'long long' (solution.cpp)
typedef long long int ll;
class Solution {
public:
    string maxValue(string n, int x) {
        int sz=n.size();
        ll res=LLONG_MIN;
        bool neg=false;
        if(n[0]=='-')
            neg=true;
        int i=neg?1:0;
        for(;i<sz;++i){
            string tmp=n;
            tmp=tmp.substr(0,i)+to_string(x)+tmp.substr(i);
            res=max(res,to_num(tmp,neg));
            //cout << tmp <<"\n";
            if(i==sz-1){
                tmp=n;
                tmp+=to_string(x);
                res=max(res,to_num(tmp,neg));
                //cout << tmp <<"\n";
            }
        }
        return to_string(res);
    }
    ll to_num(string& s,bool neg){
        ll res=0;
        for(const auto& c:s){
            if(c=='-')
                continue;
            res=res*10+(c-'0');
        }
        return neg?-res:res;
    }
};

