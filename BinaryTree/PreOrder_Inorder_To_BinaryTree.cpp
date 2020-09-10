/* Construct Binary Tree from Preorder and Inorder Traversal

Solution
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
   
Basic idea is:

preorder[0] is the root node of the tree
preorder[x] is a root node of a sub tree
In in-order traversal
When inorder[index] is an item in the in-order traversal
inorder[0]-inorder[index-1] are on the left branch
inorder[index+1]-inorder[size()-1] are on the right branch
if there is nothing on the left, that means the left child of the node is NULL
if there is nothing on the right, that means the right child of the node is NULL
Algorithm:

Start from rootIdx 0
Find preorder[rootIdx] from inorder, let's call the index pivot
Create a new node with inorder[pivot]
Create its left child recursively
Create its right child recursively
Return the created node. 

Note the use of reference for rootIdx during recursive calls*/
   
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
    TreeNode* buildUtil(vector<int>& preorder, vector<int>& inorder, int& rootIdx, int in_beg, int in_end)
    {
        if (in_beg > in_end)
            return nullptr;
        int pivot = in_beg;
        while (inorder[pivot] != preorder[rootIdx])
        {
            ++pivot;
        }
        ++rootIdx;
        TreeNode* root = new TreeNode(inorder[pivot]);
        root->left = buildUtil(preorder, inorder, rootIdx, in_beg, pivot-1);
        root->right = buildUtil(preorder, inorder, rootIdx, pivot+1, in_end);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty())
            return nullptr;
        int rootIdx = 0;
        return buildUtil(preorder, inorder, rootIdx, 0, inorder.size()-1);
    }
};