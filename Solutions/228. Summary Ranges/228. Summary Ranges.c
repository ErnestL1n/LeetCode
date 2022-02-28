

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** summaryRanges(int* nums, int numsSize, int* returnSize){
    char ** res=(char**)malloc(sizeof(char*));
    *returnSize=0;
    if(numsSize==0){
        return NULL;
    }
    for(int i=0;i<numsSize;++i){
        int st=i,ed=i;
        while(i!=numsSize-1 && nums[i]+1==nums[i+1]){
            ed=i+1;
            ++i;
        }
        ++*returnSize;
        res=realloc(res,(*returnSize)*sizeof(char*));
        res[*returnSize-1]=(char*)malloc(sizeof(char)*25);
        if(st!=ed){
            sprintf(res[*returnSize-1],"%d->%d",nums[st],nums[ed]);
        }else{
            sprintf(res[*returnSize-1],"%d",nums[st]);
        }
    }
    return res;
}