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

    TreeNode* m(TreeNode* root, int target){

        if(root == NULL){
            return NULL;
        }



        root->left = m(root->left, target);

        root->right = m(root->right, target);


        if(!root->left && !root->right && root->val == target){
            return NULL;
        }

        return root;

    }


    TreeNode* removeLeafNodes(TreeNode* root, int target) {

        TreeNode* prev = NULL;

         return m(root, target);

        //   return root;
        
    }
};