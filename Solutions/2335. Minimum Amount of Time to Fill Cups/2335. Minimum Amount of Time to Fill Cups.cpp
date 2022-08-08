class Solution {
public:
    int fillCups(vector<int>& amount) {
        int mx=0,sum=0;
        for(int& a:amount){
            mx=max(a,mx);
            sum+=a;
        }
        return max(mx,(sum+1)/2);
    }
};