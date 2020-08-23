Construct Binary Tree from Inorder and Postorder Traversal

Solution
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
   
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
 
 // Note the use of pInd as a reference as it need to be updated during recursions
class Solution {
public:
    TreeNode* buildTreeUtil(vector<int>& inorder, vector<int>& postorder, int st, int end, int& pInd)
    {
        if (st > end)
        {
            return nullptr;
        }
        TreeNode* node = new TreeNode(postorder[pInd]);
        pInd--;
        if (st == end)
            return node;
        else
        {
            int index = std::distance(inorder.begin(), std::find(inorder.begin(), inorder.end(), node->val));
            cout<<index<<endl;
            node->right = buildTreeUtil(inorder, postorder, index + 1, end, pInd); 
            node->left = buildTreeUtil(inorder, postorder, st, index - 1, pInd); 
        }
        return node;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int pInd = inorder.size()-1;
        return buildTreeUtil(inorder, postorder, 0,inorder.size()-1, pInd);
    }
};