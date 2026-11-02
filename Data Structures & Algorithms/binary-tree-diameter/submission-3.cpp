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


    int m(TreeNode* root, int &h){

        if(root == NULL){
            h = 0;
            return 0;
        }

        int lh = 0, rh = 0;

        int l = m(root->left, lh);
        int r = m(root->right, rh);

        h = max(lh, rh) + 1;


        return max(max(l,r),lh+rh+1);

    }

    int diameterOfBinaryTree(TreeNode* root) {

        int h = 0;
        return m(root, h)-1;
        
    }
};
