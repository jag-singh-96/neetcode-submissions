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

    TreeNode* minN(TreeNode* ptr){

        while(ptr && ptr->left){
            ptr = ptr->left;
        }

        return ptr;

    }
    TreeNode* deleteNode(TreeNode* root, int key) {

        if(root == NULL) return NULL;


        if(root->val < key){
            root->right = deleteNode(root->right, key);
        }else if(root->val > key){
            root->left = deleteNode(root->left, key);
        }else{

            if(root->left == NULL) return root->right;
            if(root->right == NULL) return root->left;


            TreeNode* succ = minN(root->right);

            root->val = succ->val;

            root->right = deleteNode(root->right,succ->val);

        }

        return root;

        
    }
};