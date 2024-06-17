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

    void rec(TreeNode* root, int targetSum,vector<vector<int>> &ans,int &sum ,vector<int> &temp)
    {
        //base case
        if(root==NULL)
        {
            return;
        }
        //leaf node mai kada hu

        if(root->left==NULL && root->right==NULL)
        {
            temp.push_back(root->val);
            sum+=root->val;
            if(sum==targetSum)
            {
                ans.push_back(temp);
            }
            temp.pop_back();
            sum-=root->val;
        }

       
        sum+=root->val;
   
         temp.push_back(root->val);
         rec(root->left ,targetSum,ans,sum,temp);
         rec(root->right ,targetSum,ans,sum,temp);
         // backtrack

         temp.pop_back();
         sum-=root->val;

       
        

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int> temp;
        int sum=0;
        rec(root,targetSum,ans,sum,temp);
        return ans;
    }
};