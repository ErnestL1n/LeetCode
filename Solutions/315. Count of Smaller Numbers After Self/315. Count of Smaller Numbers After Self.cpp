class FenWickTree{
    public:
    vector<int> cnt;
    FenWickTree(int n):cnt(n+1,0){

    }

    void update(int i, int delta){
        while(i<cnt.size()){
            cnt[i]+=delta;
            i+=lowbit(i);
        }
    }

    int query(int a){
        int sum=0;
        while(a>0){
            sum+=cnt[a];
            a-=lowbit(a);
        }
        return sum;
    }


    int lowbit(int x){
        return x & (-x);
    }


};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        set<int> SET(nums.begin(),nums.end());
        unordered_map<int,int> m;
        int rank=0;
        for(auto& x:SET){
            rank++;
            m[x]=rank;
        }
        FenWickTree FW(rank);
        vector<int> ans;
        for(int i=nums.size()-1;i>=0;i--){
            ans.push_back(FW.query(m[nums[i]]-1));
            FW.update(m[nums[i]],1);
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};