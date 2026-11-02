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

    void m(TreeNode* root, int &maxl, vector<int> &ans, int l){

        if(root == NULL){
            return;
        }

        if(maxl < l){
            maxl = l;
            ans.push_back(root->val);
        } 

        m(root->right, maxl, ans, l+1);
        m(root->left, maxl, ans, l+1);

    }

    vector<int> rightSideView(TreeNode* root) {

        int maxl = INT_MIN;

        vector<int> ans;

        m(root, maxl, ans, 0);

        return ans;
        
    }
};
