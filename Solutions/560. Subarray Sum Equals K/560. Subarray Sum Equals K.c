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

int subarraySum(int* nums, int numsSize, int k){
    map* table=NULL,*element;
    int sum=0,res=0;
    element=(map*)malloc(sizeof(map));
    element->idx=0;
    element->val=1;
    HASH_ADD_INT(table,idx,element);
    for(int i=0;i<numsSize;++i){
        sum+=nums[i];
        int tmp=sum-k;
        HASH_FIND_INT(table,&tmp,element);
        if(element){
            res+=element->val;
        }
        HASH_FIND_INT(table,&sum,element);
        if(element){
            element->val+=1;
        }else{
            element=(map*)malloc(sizeof(map));
            element->idx=sum;
            element->val=1;
            HASH_ADD_INT(table,idx,element);
        }
    }
    return res;
}