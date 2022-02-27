SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {
    if(!head){
        auto newhead=new SinglyLinkedListNode(data);
        newhead->next=head;
        return newhead;
    }
    auto ins=head;
    for(int i=0;i<position-1;++i){
        ins=ins->next;
    }
    auto tmp=ins->next;
    ins->next=new SinglyLinkedListNode(data);
    ins->next->next=tmp;
    return head;
}