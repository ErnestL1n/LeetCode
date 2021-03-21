class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<vector<int>> buy;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> sell;
        for(auto& o:orders){
            if(o[2]==0)
                buy.push(o);
            else
                sell.push(o);
            while(buy.size()&&sell.size()&&buy.top()[0]>=sell.top()[0]){
                int k=min(buy.top()[1],sell.top()[1]);
                vector<int> tmp=buy.top();buy.pop();
                tmp[1]-=k;
                if(tmp[1]>0)buy.push(tmp);
                tmp=sell.top();sell.pop();
                tmp[1]-=k;
                if(tmp[1]>0)sell.push(tmp);
            }
        }
        int res=0,mod=1e9+7;
        while(sell.size())
            res=(res+sell.top()[1])%mod,sell.pop();
        while(buy.size())
            res=(res+buy.top()[1])%mod,buy.pop();
        return res;
    }
};