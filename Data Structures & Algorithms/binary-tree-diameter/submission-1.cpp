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

    int m(TreeNode* root, int &maxd){

        if(root == NULL){
            // maxd = 0;
            return 0;
        }

        int l =  m(root->left, maxd);

        int r =  m(root->right, maxd);

        maxd = max(maxd,l+r);

        return max(l,r)+1;

    }
    
    int diameterOfBinaryTree(TreeNode* root) {

        int maxd = 0;

        m(root, maxd);

        return maxd;
        
    }
};
