SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* head, int data) {
    if(!head){
        head=new SinglyLinkedListNode(data);
        head->next=NULL;
        return head;
    }
    auto newhead=new SinglyLinkedListNode(data);
    newhead->next=head;
    return newhead;
}