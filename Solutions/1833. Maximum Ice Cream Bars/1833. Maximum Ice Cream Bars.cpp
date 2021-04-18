class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int res=0;
        for(const auto& c:costs){
            if(c>coins)
                break;
            ++res;
            coins-=c;
        }
        return res;
    }
};