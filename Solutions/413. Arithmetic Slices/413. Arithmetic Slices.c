

int numberOfArithmeticSlices(int* nums, int numsSize){
    int res=0,cnt=0;
    for(int i=1;i<numsSize-1;++i){
        if(nums[i]-nums[i-1]==nums[i+1]-nums[i]){
            res+=++cnt;
        } else{
            cnt=0;
        }     
    }
    return res;
}