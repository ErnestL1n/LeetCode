class Solution {
public:
    int find(vector<int>& ds,int i){
        return ds[i]<0?i:ds[i]=find(ds,ds[i]);
    }
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int sz=source.size(),res=0;
        vector<int> ds(sz,-1);
        for(auto& sw:allowedSwaps){
            int i=find(ds,sw[0]),j=find(ds,sw[1]);
            if(i!=j){
                ds[i]+=ds[j];
                ds[j]=i;
            }
        }
        vector<unordered_multiset<int>> cycles(sz);
        for(int i=0;i<sz;++i)
            if(source[i]!=target[i])
                cycles[find(ds,i)].insert(source[i]);
        for(int i=0;i<sz;++i){
            if(source[i]!=target[i]){
                // cycle here represents a hash multiset
                auto& cycle=cycles[find(ds,i)];
                auto it=cycle.find(target[i]);
                if(it!=cycle.end())
                    cycle.erase(it);
                else
                    ++res;
            }
        }
        return res;
    }
};