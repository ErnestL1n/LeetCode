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

#define and &&
#define or ||
#define max(a,b) (a>b?a:b)

int largestRectangleArea(int* heights, int heightsSize){
    heights=realloc(heights,sizeof(int)*(heightsSize+1));
    heights[heightsSize]=0;
    int n=heightsSize+1,res=0;
    struct Stack* idx=createstack(); 
    for(int i=0;i<n;++i){
        while(idx->size>0 and heights[idx->top->val]>heights[i]){
            int h=heights[idx->top->val];pop(idx);
            int l=idx->size>0?idx->top->val:-1;
            res=max(res,h*(i-l-1));
        }
        push(idx,i);
    }
    return res;
}