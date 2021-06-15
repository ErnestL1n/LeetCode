class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int res=0,curr=0;
        for(const auto& g:gain){
            curr+=g;
            res=max(res,curr);
        }
        return res;
    }
};