/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        struct Node* temp = head;
        struct Node* head2 = NULL;
        while(temp)
        {
            struct Node *newnode = new Node(temp->val);
            if(head2==NULL)
            {
                head2=newnode;
            }
            else
            {
                struct Node *temp3 = head2;
                while(temp3->next)
                {
                    temp3 = temp3 ->next;
                }
                temp3 -> next = newnode;
            }
            temp = temp ->next;
        }
        map<Node*, Node*>m;
        temp = head;
        struct Node *temp2 = head2;
        while(temp)
        {
            m[temp] = temp2;
            temp=temp->next;
            temp2=temp2->next;
        }
        temp=head;
        temp2=head2;
        while(temp)
        {
            temp2->random = m[temp->random];
            temp=temp->next;
            temp2=temp2->next;
        }
        return head2;


        
    }
};