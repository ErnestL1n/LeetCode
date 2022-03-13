struct Stack {
  struct Stack *next, *top;
  char val;
  int size;
};

struct Stack* newnode(char k) {
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

void push(struct Stack* stk, char val) {
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

bool isValid(char * s){
    struct Stack *stk=createstack();
    for(int i=0;i<strlen(s);++i){
        if(s[i]=='[' || s[i]=='(' || s[i]=='{'){
            push(stk,s[i]);
        }else{
            if(stk->size==0){
                return false;
            }
            if(s[i]==']' && stk->top->val!='['){
                return false;
            }
            if(s[i]=='}' && stk->top->val!='{'){
                return false;
            }
            if(s[i]==')' && stk->top->val!='('){
                return false;
            }
            pop(stk);
        }
    }
    return stk->size?false:true;
}