class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n<=1){
            return 0;
        }
        vector<int> hold(n),sold(n),rest(n);
        hold[0]=-prices[0];
        for(int i=1;i<n;++i){
            hold[i]=max(hold[i-1],rest[i-1]-prices[i]);
            sold[i]=hold[i-1]+prices[i];
            rest[i]=max(rest[i-1],sold[i-1]);
        }
        return max(sold[n-1],rest[n-1]);
    }
};

// O(1) space
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sold=0,rest=0,hold=INT_MIN;
        for(const auto& p:prices){
            int prev_sold=sold;
            sold=hold+p;
            hold=max(hold,rest-p);
            rest=max(rest,prev_sold);
        }
        return max(rest,sold);
    }
};