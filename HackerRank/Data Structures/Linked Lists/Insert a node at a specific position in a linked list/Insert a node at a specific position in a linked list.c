SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {
    if(position==0){
        SinglyLinkedListNode* newhead=(SinglyLinkedListNode*)malloc(sizeof(SinglyLinkedListNode));
        newhead->next=head;
        newhead->data=data;
        return newhead;
    }
    SinglyLinkedListNode* ins=head;
    for(int i=0;i<position-1;++i){
        ins=ins->next;
    }
    SinglyLinkedListNode* tmp=ins->next;
    ins->next=(SinglyLinkedListNode*)malloc(sizeof(SinglyLinkedListNode));
    ins->next->data=data;
    ins->next->next=tmp;
    return head;
}