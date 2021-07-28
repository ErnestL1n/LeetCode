class Solution {
public:
    vector<int> beautifulArray(int n) {
        vector<int> res={1};
        while(res.size()<n){
            vector<int> tmp;
            for(int x:res)
                if(x*2-1<=n)
                    tmp.push_back(x*2-1);
            for(int x:res)
                if(x*2<=n)
                    tmp.push_back(x*2);
            res=tmp;
        }
        return res;
    }
};