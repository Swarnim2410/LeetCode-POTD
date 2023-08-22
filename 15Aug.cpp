/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) 
    {
        int f=0,g=0;
        ListNode *ptr1 = NULL;
        ListNode *ptr2 = NULL;
        ListNode *temp = head;
        ListNode *head1 = NULL;
        ListNode *head2 = NULL;
        while(temp)
        {
            int a = temp->val;
            if(a<x)
            {
                if(f==0)
                {
                    head1 = temp;
                    ptr1 = temp;
                    temp=temp->next;
                    ptr1->next=NULL;
                    f=1;
                }
                else
                {
                    ptr1->next=temp;
                    temp=temp->next;
                    ptr1=ptr1->next;
                    ptr1->next=NULL;
                }
            }
            else
            {
                if(g==0)
                {
                    head2 = temp;
                    ptr2 = temp;
                    temp=temp->next;
                    ptr2->next=NULL;
                    g=1;
                }
                else
                {
                    ptr2->next=temp;
                    temp=temp->next;
                    ptr2=ptr2->next;
                    ptr2->next=NULL;
                }   
            }
        }
        if(head1==NULL)
        {
            return head2;
        }
        if(head2==NULL)
        {
            return head1;
        }
        if(ptr1)
        {
            ptr1->next=head2;
            return head1;
        }
        return NULL;
        
    }
};