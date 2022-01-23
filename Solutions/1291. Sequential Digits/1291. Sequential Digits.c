struct Queue {
  int val;
  struct Queue* next;
  struct Queue *front, *rear;
  int size;
};
struct Queue* newnode(int k) {
  struct Queue* node = (struct Queue*)malloc(sizeof(struct Queue) * 1);
  node->val = k;
  node->next = NULL;
  return node;
}
struct Queue* createQueue() {
  struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
  q->front = q->rear = NULL;
  q->size = 0;
  return q;
}

void enqueue(struct Queue* q, int k) {
  struct Queue* node = newnode(k);
  ++q->size;
  if (q->rear == NULL) {
    q->front = q->rear = node;
    return;
  }
  q->rear->next = node;
  q->rear = q->rear->next;
}

void dequeue(struct Queue* q) {
  if (!q->front) {
    return;
  }
  --q->size;
  struct Queue* tmp = q->front;
  q->front = q->front->next;
  if (!q->front) {
    q->rear = NULL;
  }
  free(tmp);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sequentialDigits(int low, int high, int* returnSize){
    struct Queue* q=createQueue();
    for(int i=1;i<=9;++i){
        enqueue(q,i);
        printf("%d\n",q->size);
        printf("%d\n",q->rear);
        printf("%d\n",q->front);
    }
    int *res=NULL;
    *returnSize=0;
    while(q->size>0){
        int f=q->front;
        dequeue(q);
        if(low<=f && f<=high){
            ++*returnSize;
            res=(int*)realloc(res,(*returnSize)*sizeof(int));
            res[(*returnSize)-1]=f;
        }
        if(f>high){
            break;
        }
        int num=f%10;
        if(num<9){
            int x=f*10+num+1;
            enqueue(q,x);
        }
    }
    return res;
}