class Solution {
public:
    int find(vector<int>& ds ,int i){
        return ds[i]<0?i:ds[i]=find(ds,ds[i]);
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        vector<vector<int>> m(s.size());
        vector<int> ds(s.size(),-1);
        for(auto& p:pairs){
            auto i=find(ds,p[0]),j=find(ds,p[1]);
            if(i!=j){
                ds[i]+=ds[j];
                ds[j]=i;
            }
        }
        for(int i=0;i<s.size();++i)
            m[find(ds,i)].push_back(i);
        for(auto& ids:m){
            string ss="";
            for(int id:ids)
                ss+=s[id];
            sort(ss.begin(),ss.end());
            for(int i=0;i<ids.size();++i)
                s[ids[i]]=ss[i];
        }
        return s;
    }
};