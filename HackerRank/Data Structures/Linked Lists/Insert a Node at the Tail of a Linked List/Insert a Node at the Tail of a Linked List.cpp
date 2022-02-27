SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
    if(!head){
        return new SinglyLinkedListNode(data);
    }
    auto tmp=head;
    while(tmp->next){
        tmp=tmp->next;
    }
    tmp->next=new SinglyLinkedListNode(data);
    return head;
}