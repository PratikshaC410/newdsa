#include <vector>
using namespace std;

class Solution {
public:
    bool cycledetectinll(node* head) {
        if(head==NULL)
        return true;
        int f=0;
        node* slow=head;
        node* fast=head;
        node* curr=head;
        while(curr->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
             if(slow==fast)
             f=1;
             else
             f=0;
        }
        if(f==1)
        return true;
        else 
        return false;
       

       
    }
};
