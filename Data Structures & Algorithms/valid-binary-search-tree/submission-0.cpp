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

    bool m(TreeNode* root, int max, int min){

        if(root == NULL) return true;

        if(root->val > max || root->val < min) return false;

        bool b1 = m(root->left, root->val-1, min);
        bool b2 = m(root->right, max, root->val+1);

        return b1 && b2;
        
    }

    bool isValidBST(TreeNode* root) {

        return m(root, INT_MAX, INT_MIN);
        
    }
};
