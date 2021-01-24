class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int res=0,cnt=0;
        for(int g:gain){
            cnt+=g;
            res=max(res,cnt);
        }
        return res;
    }
};