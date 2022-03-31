class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int sum=accumulate(nums.begin(),nums.end(),0),MAX=*max_element(nums.begin(),nums.end());
        if(m==1){
            return sum;
        }
        int lo=MAX,hi=sum;
        while(lo<hi){
            int mid=lo+hi>>1;
            if(count(nums,m,mid)){
                hi=mid;
            }else{
                lo=mid+1;
            }
        }
        return lo;
    }
    int count(vector<int>& nums,int m,int target_sum){
        int cnt=1,sum=0;
        for(auto& n:nums){
            sum+=n;
            if(sum>target_sum){
                sum=n;
                if(++cnt>m){
                    return false;
                }
            }
        }
        return true;
    }
};
