#define and &&

int findFinalValue(int* nums, int numsSize, int original){
    bool s[1001];
    memset(s,false,1001);
    for(int i=0;i<numsSize;++i){
        s[nums[i]]=true;
    }
    while(original<=1000 and s[original]){
        original*=2;
    }
    return original;
}