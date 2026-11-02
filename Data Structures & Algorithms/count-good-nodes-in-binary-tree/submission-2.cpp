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

    void m(TreeNode* root, int maxValue, int &ans){

        if(root == NULL) return;

        if(root->val >= maxValue){
            ans++;
            cout<<root->val<<" ";
            maxValue = root->val;
        }

        m(root->left, maxValue,ans);
        m(root->right, maxValue,ans);
    }

    int goodNodes(TreeNode* root) {

        int maxValue = root->val;
        int ans = 0;
        m(root, maxValue,ans);
        return ans;
        
    }
};
