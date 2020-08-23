/* You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807. */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* l1)
    {
        ListNode* prev,*current,*next;
        current = l1;
        prev=NULL;
        next=current->next;
        while(current!=NULL)
        {
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* rev1=(l1);
        ListNode* head,*temp;
        temp=rev1;
        ListNode* rev2=(l2);
         temp=rev2;
        int car=0;
        
        
        bool flag=false;
        while(rev1!=NULL && rev2!=NULL)
        {
            ListNode* l3 = new ListNode(0);
            if(!flag)
            {
                head=temp=l3;
                flag=true;
            }
            else{
                temp->next=l3;
                temp=l3;
            }
                l3->val=rev1->val+rev2->val+car;
                car=0;
                if(l3->val>=10)
                {
                    car=l3->val/10;
                    l3->val=l3->val%10;
                }
            rev1=rev1->next;
            rev2=rev2->next;
        }
        while(rev1!=NULL)
        {
            ListNode* l3 = new ListNode(0);
            l3->val=rev1->val+car;
            car=0;
            if(l3->val>=10)
            {
                car=l3->val/10;
                l3->val=l3->val%10;
            }
            temp->next=l3;
            temp=l3;
            rev1=rev1->next;
        }
        while(rev2!=NULL)
        {
            ListNode* l3 = new ListNode(0);
            l3->val=rev2->val+car;
            car=0;
            if(l3->val>=10)
            {
                car=l3->val/10;
                l3->val=l3->val%10;
            }
            temp->next=l3;
            temp=l3;
            rev2=rev2->next;
        }
        if(car!=0)
        {
            ListNode* l3 = new ListNode(1);
            temp->next=l3;
            temp=l3;
        }
        return head;
    }
};