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

    int height(TreeNode* root)
    {
        //base
        if(root==NULL)
        {
            return 0;
        }

        int leftHeight=height(root->left);
        int rightHeight=height(root->right);
        int ans=1+max(leftHeight,rightHeight);
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        // base hogya na
        // jab root hoga hei nahi toh balnaced tree hoga
        if(root==NULL)
        return true;

        int leftHeight=height(root->left);
        int rightHeight=height(root->right);
        int diff=abs(leftHeight-rightHeight);
        bool ans1=(diff<=1);

        bool ans2=isBalanced(root->left);
        bool ans3=isBalanced(root->right);

        if(ans1&& ans2 &&ans3)
        {
            return true;
        }
        
            return false;
        

    }
};