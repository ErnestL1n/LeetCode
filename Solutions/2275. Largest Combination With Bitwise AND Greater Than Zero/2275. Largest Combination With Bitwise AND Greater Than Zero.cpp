class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int res=0,mx=*max_element(candidates.begin(),candidates.end());
        for(int b=1;b<=mx;b*=2){
            int cnt=0;
            for(auto& c:candidates){
                cnt+=(c&b)>0;
            }
            res=max(res,cnt);
        }
        return res;
    }
};