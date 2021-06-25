class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parent(1001);
        for(int i=0;i<1001;++i)
            parent[i]=i;
        for(const auto& e:edges){
            int f=e[0],t=e[1];
            if(find(parent,f)==find(parent,t))
                return e;
            else
                parent[find(parent,f)]=find(parent,t);
        }
        return {-1,-1};
    }
    int find(vector<int>& parent,int f){
        if(f!=parent[f])
            parent[f]=find(parent,parent[f]);
        return parent[f];
    }
};