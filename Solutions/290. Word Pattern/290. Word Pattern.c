bool wordPattern(char* pattern, char* str) {
    int strCount = 0;
    int patternSize = strlen(pattern);
    char** translate = calloc(26, sizeof(char*));
    char *token;

    token = strtok(str, " ");
    while( token != NULL && strCount < patternSize) 
    {
        if(!translate[pattern[strCount] - 'a'])
        {
            translate[pattern[strCount] - 'a'] = token;
        }
        else
        {
            if(strcmp(translate[pattern[strCount] - 'a'], token))
            {
                return false;
            }
        }
        token = strtok(NULL, " ");
        strCount++;
    }
    
    
    if(strCount < patternSize || token != NULL) return false;
    
    for(int i = 0; i < 25; i++)
    {
        if(translate[i])
        {
        
            for(int j = i+1; j < 26; j++)
            {
                if(translate[j])
                {
                    if(strcmp(translate[i], translate[j]) == 0)
                    {
                        return false;
                    }
                }
            }
        }
    }
  
    return true;
}





/* wrong version */
struct psmap {
  char key;
  char* val;
  UT_hash_handle hh;
};

void deletemap(struct psmap** table) {
  struct psmap* cur;
  struct psmap* tmp;
  
  HASH_ITER(hh, *table, cur, tmp) {
    HASH_DEL(*table, cur);
    free(cur);
  }
}

struct spmap {
  char* key;
  char val;
  UT_hash_handle hh;
};

void deletemap2(struct spmap** table) {
  struct spmap* cur;
  struct spmap* tmp;
  
  HASH_ITER(hh, *table, cur, tmp) {
    HASH_DEL(*table, cur);
    free(cur);
  }
}

char *append(char* str,char c){
    size_t len = strlen(str);
   
    /* one for extra char, one for trailing zero */
    char *str2=(char*)malloc(sizeof(char)*(len+2));

    strcpy(str2, str);
    str2[len] = c;
    str2[len + 1] = '\0';

    return str2;

}

bool wordPattern(char * pattern, char * ss){
    struct psmap* ps=NULL,*p;
    struct spmap* sp=NULL,*s;
    int sz=0;
    char *sss[strlen(pattern)];
    char* tmp="";
        for(int i=0;i<strlen(ss);++i){
            if(ss[i]==' '){
                sss[sz++]=tmp;
                tmp="";
                continue;
            }
            tmp=append(tmp,ss[i]);
            if(i==strlen(ss)-1)
                sss[sz++]=tmp;
        }


    for(int i=0;i<sz;++i){
        HASH_FIND_INT(ps,&pattern[i],p);
        if(!p){
            p=(struct map*)malloc(sizeof(*p));
            p->val=pattern[i];
            p->key=i;
            HASH_ADD_INT(ps,val,p);
        }else{
            if(p->val!=*sss[i]){
                deletemap(&ps);
                deletemap2(&sp);
                return false;
            }
        }
    }
    for(int i=0;i<sz;++i){
        HASH_FIND_INT(sp,&sss[i],s);
        if(!s){
            s=(struct map*)malloc(sizeof(*s));
            s->val=sss[i];
            s->key=i;
            HASH_ADD_INT(sp,val,s);
        }else{
            if(s->val!=pattern[i]){
                deletemap(&ps);
                deletemap2(&sp);
                return false;
            }
        }
    }
    deletemap(&ps);
    deletemap2(&sp);
    return true;
}