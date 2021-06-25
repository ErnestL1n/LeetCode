class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ds(1001,-1);
        for(const auto& e:edges){
            int f=e[0],t=e[1];
            if(find(ds,f)==find(ds,t))
                return e;
            else
                ds[find(ds,f)]=find(ds,t);
        }
        return {-1,-1};
    }
    int find(vector<int>& ds,int i){
        return ds[i]<0?i:ds[i]=find(ds,ds[i]);
    }
};