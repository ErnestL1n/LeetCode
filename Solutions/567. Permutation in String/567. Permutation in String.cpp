//original writing AC
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int sz=s1.size();
        vector<int> w1=cnt(s1);
        for(int i=0,j=i+sz-1;j<s2.size();++i,++j){
            string x=s2.substr(i,sz);
            vector<int> tmp=cnt(x);
            if(check(w1,tmp)){
                return true;
            }
        }
        return false;
    }
    vector<int> cnt(string& x){
        vector<int> win(26);
        for(int i=0;i<x.size();++i){
            ++win[x[i]-'a'];
        }
        return win;
    }
    bool check(vector<int>& a,vector<int>& b){
        for(int i=0;i<26;++i){
            if(a[i]!=b[i]){
                return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m=s1.size(),n=s2.size();
        if(m>n){
            return false;
        }
        int cnt[26]={};
        for(int i=0;i<m;++i){
            ++cnt[s1[i]-'a'];
            --cnt[s2[i]-'a'];
        }
        if(allzero(cnt)){
            return true;
        }
        for(int i=m;i<n;++i){
            --cnt[s2[i]-'a'];
            ++cnt[s2[i-m]-'a'];
            if(allzero(cnt)){
                return true;
            }
        }
        return false;
    }
    bool allzero(int (&cnt)[26]){
        for(int i=0;i<26;++i){
            if(cnt[i]!=0){
                return false;
            }
        }
        return true;
    }
};