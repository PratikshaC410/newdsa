node middlenode(node* head)
{
    if(head==NULL)
    return ;
    if(head->next==NULL)
    return head;
    node * slow=head,fast=head;
    while(fast!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;

    }
    return slow;
}