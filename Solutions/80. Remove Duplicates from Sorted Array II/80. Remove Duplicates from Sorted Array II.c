#define or ||

int removeDuplicates(int* nums, int numsSize){
    int i=0;
    for(int j=0;j<numsSize;++j){
        if(i<2 or nums[j]>nums[i-2]){
            nums[i++]=nums[j];
        }
    }
    return i;
}