#define max(a,b) (a>b?a:b)

int maxSubArray(int* nums, int numsSize){
    int res=nums[0];
    int* dp=(int*)calloc(numsSize,sizeof(int));
    dp[0]=nums[0];
    for(int i=1;i<numsSize;++i){
        if(dp[i-1]<0){
            dp[i]=nums[i];
        }else{
            dp[i]=dp[i-1]+nums[i];
        }
        res=max(res,dp[i]);
    }
    return res;
}