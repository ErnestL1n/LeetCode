typedef struct{
    int idx,val;
    UT_hash_handle hh;
}map;

void freemap(map **table){
    map *cur,*tmp;
    HASH_ITER(hh,*table,cur,tmp){
        HASH_DEL(*table,cur);
        free(cur);
    }
}

#define max(a,b) (a>b?a:b);

int findMaxLength(int* nums, int numsSize){
    int res=0,cnt=0;
    map* table=NULL,*tmp;
    tmp=(map*)malloc(sizeof(map));
    tmp->idx=0,tmp->val=0;
    HASH_ADD_INT(table,idx,tmp);
    for(int i=0;i<numsSize;++i){
        if(nums[i]==1){
            ++cnt;
        }else{
            --cnt;
        }
        HASH_FIND_INT(table,&cnt,tmp);
        if(tmp){
            res=max(res,i+1-tmp->val);
        }else{
            tmp=(map*)malloc(sizeof(map));
            tmp->idx=cnt;
            tmp->val=i+1;
            HASH_ADD_INT(table,idx,tmp);
        }
    }
    freemap(&table);
    return res;
}