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

#define max(a,b) (a>b?a:b)

int scoreOfParentheses(char * s){
    struct Stack* stk = createstack();
    int cur=0;
    for(int i=0;i<strlen(s);++i){
        if(s[i]=='('){
            push(stk,cur);
            cur=0;
        }else{
            cur+=stk->top->val+max(cur,1);
            pop(stk);
        }
    }
    return cur;
}