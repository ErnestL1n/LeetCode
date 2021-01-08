class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int> path;
        foo(candidates,target,res,path,0);
        return res;
    }
    void foo(vector<int>& candidates,int target,vector<vector<int>>& res,vector<int>& path,int start){
        if(!target){
            res.push_back(path);
            return;
        }
        if(target<0){return;}
        for(int i=start;i<candidates.size();++i){
            if(i>start&&candidates[i]==candidates[i-1])continue;
            path.push_back(candidates[i]);
            foo(candidates,target-candidates[i],res,path,i+1);
            path.pop_back();
        }
    }
};