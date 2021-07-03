//recursive
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

//reduce computation ,hashmap memo
class Solution {
public:
    unordered_map<string,vector<int>> m;
    vector<int> diffWaysToCompute(string e) {
        vector<int> res;
        for(int i=0;i<e.size();++i){
            if(!isdigit(e[i])){
                string e1=e.substr(0,i);
                string e2=e.substr(i+1);
                auto p1=m.find(e1)!=m.end()?m[e1]:diffWaysToCompute(e1);
                auto p2=m.find(e2)!=m.end()?m[e2]:diffWaysToCompute(e2);
                for(const auto& x:p1)
                    for(const auto& y:p2){
                        int cnt=0;
                        if(e[i]=='+')
                            cnt+=x+y;
                        else if(e[i]=='-')
                            cnt+=x-y;
                        else 
                            cnt+=x*y;
                        res.push_back(cnt);
                    }
            }
        }
        if(res.size()==0)
            res.push_back(stoi(e));
        m[e]=res;
        return res;
    }
};