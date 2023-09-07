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
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        int a = left-1;
        int b = right-1;
        ListNode *temp1 = head;
        ListNode *newhead = head;
        ListNode *pre1 = NULL;
        ListNode *pre2 = NULL;
        ListNode *temp2 = head;
        while(a--)
        {
            pre1 = temp1;
            //left previous
            temp1=temp1->next;
        }
        while(b--)
        {
            temp2=temp2->next;
        }
        if(temp2->next)
        {
            //right next
            pre2 = temp2->next;
        }
        ListNode *one = NULL;
        ListNode *two = temp1;
        ListNode *three;
        while (two!=pre2)
        {
            three = two->next;
            two->next = one;
            one = two;
            two = three;
        }
        head = one;
        if(pre1)
        {
            pre1->next = head;
            head = newhead;
        }
        ListNode *var = head;
        while(var->next)
        {
            var = var->next;
        }
        var->next = pre2;
        return head;
    }
};