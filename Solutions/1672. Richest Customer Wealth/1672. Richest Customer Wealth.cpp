class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int m=accounts.size(),n=accounts[0].size(),res=-1;
        for(int i=0;i<m;++i){
            int s=0;
            for(int j=0;j<n;++j){
                s+=accounts[i][j];
            }
            res=max(res,s);
        }
        return res;
    }
};