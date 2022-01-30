// nums = "----->-->"; k =3
// result = "-->----->";

// reverse "----->-->" we can get "<--<-----"
// reverse "<--" we can get "--><-----"
// reverse "<-----" we can get "-->----->"

void reverse(int* nums,int lo,int hi){
    while(lo<hi){
        int tmp=nums[lo];
        nums[lo]=nums[hi];
        nums[hi]=tmp;
        ++lo,--hi;
    }
}

void rotate(int* nums, int numsSize, int k){
    k%=numsSize;
    reverse(nums,0,numsSize-1);
    reverse(nums,0,k-1);
    reverse(nums,k,numsSize-1);
}
