class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        const int mod=1e9+7;
        unordered_map<int,long> um;
        for(auto& a:arr){
            ++um[a];
        }
        long res=0;
        for(auto& [k1,v1]:um){
            for(auto& [k2,v2]:um){
                int i=k1,j=k2,k=target-i-j;
                if(!um.count(k)){
                    continue;
                }
                if(i==j and j==k){
                    res+=um[i]*(um[i]-1)*(um[i]-2)/6;
                }else if(i==j and j!=k){
                    res+=um[i]*(um[i]-1)*um[k]/2;
                }else if(i<j and j<k){
                    res+=um[i]*um[j]*um[k];
                }
            }
        }
        return res%mod;
    }
};