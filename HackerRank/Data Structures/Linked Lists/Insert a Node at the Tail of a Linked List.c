SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
    if(head==NULL){
        head=(SinglyLinkedListNode*)malloc(sizeof(SinglyLinkedListNode));
        head->next=NULL;
        head->data=data;
        return head;
    }
    SinglyLinkedListNode* tmp=head;
    while(tmp->next!=NULL){
        tmp=tmp->next;
    }
    tmp->next=(SinglyLinkedListNode*)malloc(sizeof(SinglyLinkedListNode));
    tmp->next->next=NULL;
    tmp->next->data=data;
    return head;
}
