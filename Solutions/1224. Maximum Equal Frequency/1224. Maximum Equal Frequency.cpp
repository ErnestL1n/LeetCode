class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        unordered_map<int,int> cnt,freq;
        int maxF=0,res=0;
        for(int i=0;i<nums.size();++i){
            cnt[nums[i]]+=1;
            freq[cnt[nums[i]]-1]-=1;
            freq[cnt[nums[i]]]+=1;
            maxF=max(maxF,cnt[nums[i]]);
            if(maxF*freq[maxF]==i or (maxF-1)*(freq[maxF-1]+1)==i or maxF==1)
                res=i+1;
        }
        return res;
    }
};