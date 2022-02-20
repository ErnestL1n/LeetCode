#define ll long long 
class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if(finalSum%2){
            return {};
        }
        vector<ll> res;
        ll i=2,cursum=0;
        while(cursum+i<=finalSum){
            res.push_back(i);
            cursum+=i;
            i+=2;
        }
        res.back()+=finalSum-cursum;
        return res;
    }
};