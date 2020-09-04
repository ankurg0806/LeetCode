/* Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5 */

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
    ListNode* removeElements(ListNode* head, int val) {
        if (not head)
            return head;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr !=nullptr)
        {
            if (curr->val == val)
            {
                if (prev)
                {
                    prev->next = curr->next;
                    delete curr;
                    curr = prev->next;
                }
                else
                {
                    ListNode* temp = curr;
                    curr = curr->next;
                    head = curr;
                    delete temp;
                }
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};