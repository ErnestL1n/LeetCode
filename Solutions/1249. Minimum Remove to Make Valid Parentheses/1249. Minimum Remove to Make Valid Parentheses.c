struct Stack {
  struct Stack *next, *top;
  int val;
  int size;
};

struct Stack* newnode(int k) {
  struct Stack* node = (struct Stack*)malloc(sizeof(struct Stack));
  node->val = k;
  node->next = NULL;
  return node;
}

struct Stack* createstack() {
  struct Stack* stk = (struct Stack*)malloc(sizeof(struct Stack));
  stk->top = NULL;
  stk->size = 0;
  return stk;
}

int empty(struct Stack* stk) { return !stk->top; }

void push(struct Stack* stk, int val) {
  struct Stack* node = newnode(val);
  ++stk->size;
  if (stk->top == NULL) {
    stk->top = node;
    return;
  }
  node->next = stk->top;
  stk->top = node;
}

void pop(struct Stack* stk) {
  if (!stk->top) {
    printf("stk is empty!!\n");
    return;
  }
  --stk->size;
  struct Stack* tmp = stk->top;
  stk->top = stk->top->next;
  free(tmp);
}

char * minRemoveToMakeValid(char * s){
    struct Stack* stk = createstack();
    for(int i=0;i<strlen(s);++i){
        if(s[i]=='('){
            push(stk,i);
        }
        if(s[i]==')'){
            if(stk->size){
                pop(stk);
            }else{
                *(s+i)='#';
            }
        }
    }
    while(stk->size){
        *(s+stk->top->val)='#';
        pop(stk);
    }
    char* res=calloc(strlen(s),sizeof(char));
    for(int i=0,j=0;i<strlen(s);++i){
        if(s[i]=='#'){
            continue;
        }
        *(res+j)=s[i];
        ++j;
    }
    return res;
}