#include <stdio.h>
#include <stdlib.h>

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

bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize){
    struct Stack* stk = createstack();
    int i=0;
    for(int j=0;j<pushedSize;++j){
        push(stk,pushed[j]);
        while(stk->size && stk->top->val==popped[i]){
            pop(stk);
            ++i;
        }
    }
    return stk->size==0;
}