

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct{
    int idx,val;
    UT_hash_handle hh;
}map;

void freemap(map** table) {
  map* cur;
  map *tmp;
  
  HASH_ITER(hh,*table,cur,tmp) {
    HASH_DEL(*table,cur);
    free(cur);
  }
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    map *table=NULL,*element=NULL;
    int* res=(int*)malloc(2*sizeof(int));
    for(int i=0;i<numsSize;++i){
        int r=target-nums[i];
        HASH_FIND_INT(table,&r,element);
        if(element){
            res[0]=i;
            res[1]=element->val;
            break;
        }
        // HASH_FIND_INT(table,&nums[i],element);
        // if(!element){
        element=(map*)malloc(sizeof(map));
        element->idx=nums[i];
        element->val=i;
        HASH_ADD_INT(table,idx,element);
        // }
    }
    freemap(&table);
    *returnSize=2;
    return res;
}