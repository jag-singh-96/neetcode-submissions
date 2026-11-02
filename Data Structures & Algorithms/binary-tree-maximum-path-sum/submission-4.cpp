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

    int m(TreeNode* root, int &maxSum){
        if(root == NULL){
            return 0;
        }

        int l = m(root->left, maxSum);

        int r = m(root->right, maxSum);

        int maxS = max(max(l,r)+root->val,root->val);

        maxSum = max(maxSum, max(l+r+root->val,maxS));

        return maxS;



    }

    int maxPathSum(TreeNode* root) {

        int maxSum = INT_MIN;

        m(root, maxSum);

        return maxSum;

    }
};
