/* Given a binary tree, flatten it to a linked list in-place.

For example, given the following tree:

    1
   / \
  2   5
 / \   \
3   4   6
The flattened tree should look like:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten_util(TreeNode* root)
    {
        if (not root)
            return;
        if (root->left)
            flatten_util(root->left);
        if (root->right)
            flatten_util(root->right);
        TreeNode* temp = root->right;
        if (root->left)
        {
            root->right = root->left;
            root->left = nullptr;
            TreeNode* temp1 = root->right;
            while(temp1->right!=nullptr)
            {
                temp1 = temp1->right;
            }
            temp1->right = temp;       
        }                                                                                                                              
    }
    void flatten(TreeNode* root) {
        flatten_util(root);
    }
};