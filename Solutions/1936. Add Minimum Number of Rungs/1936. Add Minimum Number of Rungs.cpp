class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int res=0;
        rungs.insert(rungs.begin(),0);
        for(int i=1;i<rungs.size();++i){
            if(rungs[i]-rungs[i-1]>dist)
                res+=(rungs[i]-rungs[i-1]-1)/dist;
        }
        return res;
    }
};