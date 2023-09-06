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

    int countnodes(ListNode *head)
    {
        int cnt=0;
        ListNode *temp = head;
        while(temp)
        {
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) 
    {
        int num = countnodes(head); 
        int maxi = num/k;
        int left = num%k;
        int left2 = left;
        vector<ListNode *>v;
        ListNode *temp = head;
        ListNode *pre = NULL;
        ListNode *ptr = NULL;
        while(temp)
        {
            ptr = temp;
            int curr = maxi;
            while(temp && curr)
            {
                pre = temp;
                temp=temp->next;
                curr--;
            }
            if(left)
            {
                pre=temp;
                temp=temp->next;
                left--;
            }
            pre->next=NULL;
            v.push_back(ptr);
        }
        if(maxi==0)
        {
            int val = k - left2;
            while(val)
            {
                v.push_back(NULL);
                val--;
            }
        }
        return v;
    }
};