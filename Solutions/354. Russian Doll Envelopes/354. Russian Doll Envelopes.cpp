class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        vector<int> candidates;
        sort(envelopes.begin(),envelopes.end(),[](vector<int>& a,vector<int>& b){
            if(a[0]==b[0]){
                return a[1]>b[1];
            }
            return a[0]<b[0];
        });
        vector<int> dp;
        for(int i=0;i<envelopes.size();++i){
            auto itr=lower_bound(dp.begin(),dp.end(),envelopes[i][1]);
            if(itr==dp.end()){
                dp.push_back(envelopes[i][1]);
            }else{
                *itr=envelopes[i][1];
            }
        }
        return dp.size();
    }
};