class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> stk;
        for(int i=0;i<prices.size();++i){
            while(stk.size()&&prices[stk.back()]>=prices[i]){
                prices[stk.back()]-=prices[i];
                stk.pop_back();
            }
            stk.push_back(i);
        }
        return prices;
    }
};