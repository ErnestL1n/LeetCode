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





/* using uthash */
typedef struct {
  char key[2];
  char* val;
  UT_hash_handle hh;
}psmap;

void deletemap(psmap** table) {
  psmap* cur;
  psmap* tmp;
  
  HASH_ITER(hh,*table,cur,tmp) {
    HASH_DEL(*table,cur);
    free(cur);
  }
}

typedef struct {
  char* key;
  char val[2];
  UT_hash_handle hh;
}spmap;

void deletemap2(spmap** table) {
  spmap* cur;
  spmap* tmp;
  
  HASH_ITER(hh,*table,cur,tmp) {
    HASH_DEL(*table,cur);
    free(cur);
  }
}

char *append(char* str,char c){
    size_t len=strlen(str);
    char *str2=(char*)malloc(sizeof(char)*(len+2));
    strcpy(str2,str);
    str2[len]=c;
    str2[len+1]='\0';
    return str2;
}


bool wordPattern(char * pattern, char * ss){
    psmap* ps=NULL,*p;
    spmap* sp=NULL,*s;
    int sz=0;
    char *sss[strlen(pattern)];
    char *tmp="";
    for(int i=0;i<strlen(ss);++i){
        if(ss[i]==' '){
            sss[sz++]=tmp;
            tmp="";
            continue;
        }
        tmp=append(tmp,ss[i]);
        if(i==strlen(ss)-1){
            if(sz>=strlen(pattern)){
                return false;
            }
            sss[sz++]=tmp;
        }
    }
    
    if(sz!=strlen(pattern)){
        return false;
    }
    
    for(int i=0;i<sz;++i){
        char *tmp=(char *)malloc(2);
        tmp[0]=pattern[i];
        tmp[1]='\0';
        HASH_FIND_STR(ps,tmp,p);
        if(!p){
            p=(psmap*)malloc(sizeof(psmap));
            char x[2];
            x[0]=pattern[i];
            x[1]='\0';
            strcpy(p->key,x); 
            p->val=sss[i];
            HASH_ADD_STR(ps,key,p);
        }else{
            printf(p->key);
            printf(p->val);
            if(strcmp(p->val,sss[i])!=0){
                deletemap(&ps);
                deletemap2(&sp);
                return false;
            }
        }
    }
    for(int i=0;i<sz;++i){
        HASH_FIND_STR(sp,sss[i],s);
        if(!s){
            s=(spmap*)malloc(sizeof(spmap));
            s->key=sss[i];
            char x[2];
            x[0]=pattern[i];
            x[1]='\0';
            strcpy(s->val,x);
            // printf(s->key);
            // printf(s->val);
            HASH_ADD_KEYPTR(hh,sp,s->key,strlen(s->key),s);
        }else{
            // printf("ok");
            // printf("%s\n", s->key);
            // printf("%s\n", s->val);
            char *tmp=(char *)malloc(2);
            tmp[0]=pattern[i];
            tmp[1]='\0';
            if(strcmp(s->val,tmp)!=0){
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