SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* head, int data) {
    if(!head){
        head=(SinglyLinkedListNode*)malloc(sizeof(SinglyLinkedListNode));
        head->next=NULL;
        head->data=data;
        return head;
    }
    SinglyLinkedListNode* newhead=(SinglyLinkedListNode*)malloc(sizeof(SinglyLinkedListNode));
    newhead->data=data;
    newhead->next=head;
    return newhead;
}