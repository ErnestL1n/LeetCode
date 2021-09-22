class Solution {
public:
    int res=0;
    void dfs(vector<int>& a,int start,int mask){
        res=max(res,__builtin_popcount(mask));
        for(int i=start;i<a.size();++i){
            //valid
            if((mask&a[i])==0)
                dfs(a,i+1,mask|a[i]);
        }
    }
    int maxLength(vector<string>& arr) {
        vector<int> a;
        for(const auto& s:arr){
            int mask=0;
            for(const char& c:s)
                mask|=1<<(c-'a');
            //have duplicate character
            if(__builtin_popcount(mask)!=s.size())
                continue;
            a.push_back(mask);
        }
        dfs(a,0,0);
        return res;
    }
};