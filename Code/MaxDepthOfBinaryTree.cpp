/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/7/trees/47/
*/
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        
        int l = 0, r = 0, res = 0;
        
        if(root->left == NULL)
        {
            if(root->right == NULL)
                return 1;
            return 1 + maxDepth(root->right);
        }

        if(root->right == NULL)
            return 1 + maxDepth(root->left);
        
        l = maxDepth(root->left);
        r = maxDepth(root->right);
        res = l>r?l:r;
        return res+1;
        
    }
};