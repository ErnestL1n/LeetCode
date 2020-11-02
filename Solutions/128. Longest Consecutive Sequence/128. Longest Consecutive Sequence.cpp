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