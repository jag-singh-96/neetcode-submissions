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

    int m(TreeNode* root, int &maxD){

        if(root == NULL) return 0;


        int l = m(root->left, maxD);
        int r = m(root->right, maxD);

        maxD = max(maxD,max(l+r,max(l,r)));


        return max(l,r)+1;


    }

    int diameterOfBinaryTree(TreeNode* root) {


        if(root == NULL) return 0;

        int maxD = 0;

        m(root, maxD);

        return maxD;
        
    }
};
