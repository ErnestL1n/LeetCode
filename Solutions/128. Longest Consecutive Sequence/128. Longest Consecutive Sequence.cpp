// HashSet implementation,while using set(RB tree) is slower
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        int seq=0;
        for(auto x:s){
            if(!s.count(x-1)){
                int cnt=0;
                while(s.count(x++))
                    ++cnt;
                seq=max(seq,cnt);
            }
        }
        return seq;
    }
};

//Sort
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(!nums.size())
            return 0;
        sort(nums.begin(),nums.end());
        int longstreak=1,currstreak=1;
        for(int i=1;i<nums.size();++i){
            if(nums[i]!=nums[i-1]){
                if(nums[i]==nums[i-1]+1)
                    ++currstreak;
                else{
                    longstreak=max(longstreak,currstreak);
                    currstreak=1;
                }
            }
        }
        return max(longstreak,currstreak);
    }
};

//Union Find

class Solution {
public:
    int find(vector<int>& ds,int i){
        return ds[i]<0?i:find(ds,ds[i]);
    }
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        int res=0;
        unordered_map<int,int> mp;
        vector<int> ds(nums.size(),-1);
        for(int i=0;i<nums.size();++i){
            int x=nums[i];
            if(mp.count(x))
                continue;
            mp[x]=i;
            if(mp.count(x-1)){
                int j=find(ds,mp[x]);
                int k=find(ds,mp[x-1]);
                ds[j]+=ds[k];
                ds[k]=j;
            }
            if(mp.count(x+1)){
                int j=find(ds,mp[x]);
                int k=find(ds,mp[x+1]);
                ds[j]+=ds[k];
                ds[k]=j;
            }
            res=max(res,abs(ds[find(ds,mp[x])]));
        }
        return res;
    }
};