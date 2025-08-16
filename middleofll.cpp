/*
 * Definition for singly-linked list.
 * struct node {
 *     int val;
 *     node *next;
 *     node() : val(0), next(nullptr) {}
 *    node(int x) : val(x), next(nullptr) {}
 *   node(int x, node*next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    node* middleofll(node* head) {
  if(head==NULL || head->next==NULL)
  return head;
  node* slow=head;
  node* fast=head;
  node* curr=head;
  while(curr->next!=NULL)
  {
    slow=slow->next;
    fast=fast->next->next;

  }  
  return slow;  
    }
};
