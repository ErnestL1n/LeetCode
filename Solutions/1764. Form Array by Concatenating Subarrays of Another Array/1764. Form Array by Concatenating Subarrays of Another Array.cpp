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

// 1. greedy recursion
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

//2. kmp
class Solution {
public:
        vector<int> buildPrefix(vector<int> &v) {
        vector<int> kmp(v.size() + 1);
        for (int slow = 0, fast = 1; fast < v.size(); ++fast) {
            if (v[slow] == v[fast]) {
                kmp[fast + 1] = ++slow;
            }
            else if (slow != 0) {
                slow = kmp[slow];
                --fast;
            }
        }    
        return kmp;
        }
        bool canChoose(vector<vector<int>>& g, vector<int>& nums, int i = 0, int j = 0) {
            if (i >= g.size())
                return true;
            auto kmp = buildPrefix(g[i]);
            for (int k = 0; j <= nums.size() - g[i].size(); ++k) {
                if (k == g[i].size())
                    return canChoose(g, nums, i + 1, j + k);   
                if (nums[j + k] != g[i][k]) {
                    j += max(1, k - kmp[k]);
                    k = kmp[k] - 1;            
                }
            }
            return false;
            }
};