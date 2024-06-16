/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        // base case 
        if(root==NULL)
        {
            return NULL;
        }
        if(root->val == q->val )
        {
            return q;
        }
        if(root->val==p->val)
        {
            return p;
        }
        TreeNode* leftans=lowestCommonAncestor(root->left,p,q);
        TreeNode* rightans=lowestCommonAncestor(root->right,p,q);

        if(leftans!=NULL && rightans!=NULL)
        {
            return root;
        }
        else if(leftans==NULL &&rightans==NULL )
        {
            return NULL;
        }
        else if(leftans!=NULL && rightans==NULL)
        {
            return leftans;
        }
        else  
        {
            return rightans;
        }

    }
};