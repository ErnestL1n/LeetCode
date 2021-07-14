class Solution {
public:
    string customSortString(string order, string str) {
        if(order.size()==0)
            return str;
        string res="";
        map<int,char> m;
        for(int i=0;i<order.size();++i)
            m[i]=order[i];
        int cnt[26]={0};
        for(const auto& c:str)
            ++cnt[c-'a'];
        for(const auto& [k,v]:m){
            while(cnt[v-'a']-->0)
                res+=v;        
        }
        for(int i=0;i<26;++i){
            while(cnt[i]-->0)
                res+=i+'a';
        }
        return res;
    }
};

//not using map
class Solution {
public:
    string customSortString(string order, string str) {
        if(order.size()==0)
            return str;
        string res="";
        int m[26]={0};
        for(int i=0;i<order.size();++i)
            m[i]=order[i];
        int cnt[26]={0};
        for(const auto& c:str)
            ++cnt[c-'a'];
        for(int i=0;i<order.size();++i){
            while(cnt[order[i]-'a']-->0)
                res+=order[i];        
        }
        for(int i=0;i<26;++i){
            while(cnt[i]-->0)
                res+=i+'a';
        }
        return res;
    }
};