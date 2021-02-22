class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int i=0;
        for(auto& g:groups){
            bool ok=false;
            while(i+g.size()<=nums.size()){
                if(vector<int>(nums.begin()+i,nums.begin()+i+g.size())==g){
                    ok=true;
                    i+=g.size();
                    break;
                }
                else
                    ++i;
            }
            if(!ok)return false;
        }
        return true;
    }
};