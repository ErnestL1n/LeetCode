typedef vector<vector<int>> VVI;
typedef vector<int> VI;
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        VVI res;
        VI path;
        foo(res,path,candidates,target,0);
        return res;
    }
    void foo(VVI& res,VI& path,VI& c,int t,int begin){
        if(t<=0){
            if(!t){
                res.push_back(path);
                return;
            }
            return;
        }
        for(int i=begin;i<c.size();++i){
            path.push_back(c[i]);
            foo(res,path,c,t-c[i],i);
            path.pop_back();
        }
        return;
    }
};