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


    void get(TreeNode* root, int max_v, int &count){

        if(root == NULL) return;

        if(root->val >= max_v){
            count++;
        }

        max_v = max(max_v, root->val);

        get(root->left, max_v, count);
        get(root->right, max_v, count);

    }

    int goodNodes(TreeNode* root) {

        if(root == NULL) return 0;

        int max_v = root->val;

        int count = 0;

        get(root, max_v,count);

        return count;


        
    }
};
