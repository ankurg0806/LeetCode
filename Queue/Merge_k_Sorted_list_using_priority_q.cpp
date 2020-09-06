/* 23. Merge k Sorted Lists

You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
 */


//Solution 1 using priority queue

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
struct compare
{
    bool operator()(const ListNode* l1, const ListNode* l2)
    {
        return l1->val > l2->val;
    }
};
class Solution {
public:
    
    ListNode *mergeKLists(vector<ListNode *> &lists) 
    {
        priority_queue<ListNode *, vector<ListNode *>, compare> q;
        // will insert the first node of each list in priority queue
        for(auto l : lists) 
        {
            if(l)
            {
                q.push(l);
            }
        }
        if(q.empty())  
            return NULL;
        //make result node which will be the first node in sorted list
        ListNode* result = q.top();
        q.pop();
        // once you got the smallest element, you need to push the next of that smallest element into the PQ
        if(result->next) 
        {
            q.push(result->next);
        }
        ListNode* tail = result;   
        while (!q.empty())
        {
            tail->next = q.top();
            q.pop();
            tail = tail->next;
            //keep putting the next of the smallest element from corresponding lists
            if (tail->next)
            {
                q.push(tail->next);
            }
        }
        return result;
    }
};


// Using max_heap
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
bool compare(const ListNode* l1, const ListNode* l2)
{
    return l1->val > l2->val;
}
class Solution {
public:
    
    ListNode *mergeKLists(vector<ListNode *> &lists) 
    {
        // start with inserting first element of all list into l
        vector<ListNode *> l;
        for (auto lnode: lists)
        {
            if(lnode)
            {
                l.push_back(lnode);
            }
        }
        if (l.empty())
            return nullptr;
        make_heap(l.begin(), l.end(), compare);
        ListNode* result = l.front();
        // pop_heap will move the smallest element to the last
        pop_heap(l.begin(), l.end(), compare);
        // remove last
        l.pop_back();
        if(result->next)
        {
            l.push_back(result->next);
            push_heap(l.begin(), l.end(), compare);
        }
        ListNode* tail = result;
        while (!l.empty())
        {
            tail->next = l.front();
            pop_heap(l.begin(), l.end(), compare);
            l.pop_back();
            tail = tail->next;
            if (tail->next)
            {
                l.push_back(tail->next);
                push_heap(l.begin(), l.end(), compare);
            }
        }
        return result;
    }
};