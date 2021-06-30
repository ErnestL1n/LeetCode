class Solution {
public:
    vector<int> diffWaysToCompute(string e) {
        vector<int> res;
        for(int i=0;i<e.size();++i){
            if(!isdigit(e[i])){
                auto p1=diffWaysToCompute(e.substr(0,i));
                auto p2=diffWaysToCompute(e.substr(i+1));
                for(const auto& x:p1){
                    for(const auto& y:p2){
                        int cnt=0;
                        if(e[i]=='+')
                            cnt=x+y;
                        else if(e[i]=='-')
                            cnt=x-y;
                        else
                            cnt=x*y;
                        res.push_back(cnt);
                    }
                }
            }
        }
        if(res.size()==0)
            res.push_back(stoi(e));
        return res;
    }
};