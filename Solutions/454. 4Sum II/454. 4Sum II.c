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

int fourSumCount(int* nums1, int nums1Size, int* nums2, int nums2Size, int* nums3, int nums3Size, int* nums4, int nums4Size){
    int res=0;
    map* table=NULL,*element=NULL;
    for(int i=0;i<nums1Size;++i){
        for(int j=0;j<nums2Size;++j){
            int tmp=nums1[i]+nums2[j];
            HASH_FIND_INT(table,&tmp,element);
            if(element){
                element->val=element->val+1;
            }else{
                element=(map*)malloc(sizeof(map));
                element->idx=tmp;
                element->val=1;
                HASH_ADD_INT(table,idx,element);   
            }
        }
    }
    for(int i=0;i<nums3Size;++i){
        for(int j=0;j<nums4Size;++j){
            int tmp=-nums3[i]-nums4[j];
            HASH_FIND_INT(table,&tmp,element);
            if(element){
                res+=element->val;
            }
        }
    }
    return res;
}