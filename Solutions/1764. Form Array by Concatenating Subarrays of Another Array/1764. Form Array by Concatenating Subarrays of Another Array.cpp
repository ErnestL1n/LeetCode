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


//vortubac method

// 1.
class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums, int i = 0, int j = 0) {
        if (i >= groups.size())
            return true;
        for (; j <= nums.size() - groups[i].size(); ++j) {
            for (auto gi = 0; gi <= groups[i].size(); ++gi) {
                    if (gi == groups[i].size())
                    return canChoose(groups, nums, i + 1, j + groups[i].size());
                if (nums[j + gi] != groups[i][gi])
                    break;
            }
        }
        return false;
    }
};

//kmp