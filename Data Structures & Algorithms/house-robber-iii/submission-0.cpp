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

    unordered_map<TreeNode*, int> dp;
    int rob(TreeNode* root) {

        if(root == NULL) return 0;

        int include = 0;

        int exclude = 0;

        if(dp.find(root) != dp.end()) return dp[root];

        include += root->val;

        if(root->left){
            if(root->left->left){
                include += rob(root->left->left);
            }
            if(root->left->right){
                include += rob(root->left->right);
            }
            exclude += rob(root->left);
        }

        if(root->right){

            if(root->right->left){
                include += rob(root->right->left);
            }

            if(root->right->right){
                include += rob(root->right->right);
            }
            exclude += rob(root->right);
        }

        return dp[root] = max(include,exclude);





        
    }
};