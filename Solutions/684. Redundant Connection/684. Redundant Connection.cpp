class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parent(1001,-1);
        for(const auto& e:edges){
            int f=e[0],t=e[1];
            if(find(parent,f)==find(parent,t))
                return e;
            else
                parent[find(parent,f)]=find(parent,t);
        }
        return {-1,-1};
    }
    int find(vector<int>& ds,int i){
        return ds[i]<0?i:ds[i]=find(ds,ds[i]);
    }
};