class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold1=INT_MIN,hold2=INT_MIN;
        int release1=0,release2=0;
        for(const auto& p:prices){
            release2 = max(release2, hold2+p);     
            hold2    = max(hold2,    release1-p); 
            release1 = max(release1, hold1+p);     
            hold1    = max(hold1,    -p);   
        }
        return release2;
    }
};