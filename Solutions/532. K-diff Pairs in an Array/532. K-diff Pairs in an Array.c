typedef struct{
    int idx,val;
    UT_hash_handle hh;
}map;

void freemap(map** table){
    map* cur,*tmp;
    HASH_ITER(hh,*table,cur,tmp){
        HASH_DEL(*table,cur);
        free(cur);
    }
}

int findPairs(int* nums, int numsSize, int k){
    int res=0;
    map* table=NULL,*element=NULL;
    for(int i=0;i<numsSize;++i){
        HASH_FIND_INT(table,&nums[i],element);
        if(element){
            element->val+=1;
        }else{
            element=(map*)malloc(sizeof(map));
            element->idx=nums[i];
            element->val=1;
            HASH_ADD_INT(table,idx,element); 
        }
    }
    for(map* x=table;x;x=x->hh.next){
        if(k==0){
            if(x->val>1){
                ++res;
            }
        }else{
            int tmp=x->idx+k;
            HASH_FIND_INT(table,&tmp,element);
            if(element){
                ++res;
            }
        }
    }
    freemap(&table);
    return res;
}