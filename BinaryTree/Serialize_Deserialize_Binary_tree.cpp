/* 297. Serialize and Deserialize Binary Tree
Hard

Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Example: 

You may serialize the following tree:

    1
   / \
  2   3
     / \
    4   5

as "[1,2,3,null,null,4,5]"
Clarification: The above format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.

Solution: 

The solution uses DFS (preorder traversal of the tree to get the serialized string) and again dfs to deserialize it
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    vector<TreeNode*> res;
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        std::string result="";
        if (!root)
            return "null";
        result += std::to_string(root->val) +"," + serialize(root->left) + "," + serialize(root->right);
        return result;
    }

    TreeNode* deserializeUtil(std:: istringstream& datastream) {
        std::string token;
        TreeNode* root = nullptr;
        if (std::getline(datastream, token, ','))
        {
            if (token == "null") {
                return root;
            } 
            else {
                TreeNode* root = new TreeNode(stoi(token));
                root->left = deserializeUtil(datastream);
                root->right = deserializeUtil(datastream);
                return root;
            }
        }
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        cout<<data;
        if (data.empty() or data == "null") return nullptr;
        std::istringstream datastream(data);
        return deserializeUtil(datastream);
    }
};

/* Your input
[1,2,3,null,null,4,5]
stdout
1,2,null,null,3,4,null,null,5,null,null
Output
[1,2,3,null,null,4,5]
Expected
[1,2,3,null,null,4,5] */



// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));