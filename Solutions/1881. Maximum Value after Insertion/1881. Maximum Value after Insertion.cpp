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


//right answer
//The main idea is, if there is a negative sign. You wanted to make the value to be as minimum as possible when you ignore the negative sign.
class Solution {
public:
    string maxValue(string n, int x) {
        bool neg=false;
        if(n[0]=='-')
            neg=true,n=n.substr(1);
        if(neg){
            for(int i=0;i<n.size();++i)
                if(x<n[i]-'0')
                    return "-"+n.substr(0,i)+to_string(x)+n.substr(i);
            return "-"+n+to_string(x);
        }else{
            for(int i=0;i<n.size();++i)
                if(x>n[i]-'0')
                    return n.substr(0,i)+to_string(x)+n.substr(i);
            return n+to_string(x);
        }
        return n;
    }
};