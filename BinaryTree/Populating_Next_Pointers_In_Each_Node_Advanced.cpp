/* Populating Next Right Pointers in Each Node II

Solution
Given a binary tree (not a complete binary tree)
e.g
                      1
					/   \
				   2     3
				  / \     \
				 4   5     7

				 th output should be
                      1--> null
					/   \
				   2---->3-->null
				  / \     \
				 4-->5---->7-->null				 
				 
struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

 

Follow up:

You may only use constant extra space.
Recursive approach is fine, you may assume implicit stack space does not count as extra space for this problem.
 

Example 1:



Input: root = [1,2,3,4,5,null,7]
Output: [1,#,2,3,#,4,5,7,#]
Explanation: Given the above binary tree (Figure A), your function should populate each next pointer to point to its */

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root)
            return root;
        Node* leftmost = root;
        Node* prev = nullptr; // previous is referring the nodes on next level, if it is null means you are at 
                              // leftmost node
        Node* curr = nullptr;
        while (leftmost != nullptr)
        {
            curr = leftmost;
            prev = nullptr;
            leftmost = nullptr;
            while (curr != nullptr)
            {
                if (curr->left)
                {
                    // prev is null, you are at leftmost node
                    if (prev == nullptr)
                        leftmost = curr->left;
                    else
                    {
                        prev->next = curr->left;
                    }
                    prev = curr->left;
                }
                if (curr->right)
                {
                    // prev is null, you are at leftmost node, eventhough it exist in right child of the parent
                    if (prev == nullptr)
                        leftmost = curr->right;
                    else
                    {
                        prev->next = curr->right;
                    }
                    prev = curr->right;
                }
                cout<<curr->val;
                curr = curr->next;
            }
        }
        return root;
    }
};