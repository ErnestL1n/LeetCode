int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode* a=head1,*b=head2;
    while(a!=b){
        a=a?a->next:head2;
        b=b?b->next:head1;
    }
    return a->data;
}