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
    TreeNode* ans = NULL;
    void m(TreeNode* root, TreeNode* p, TreeNode* q){

        if(root == NULL) return ;


        if((root->val >= p->val && root->val <= q->val) || (root->val <= p->val && root->val >= q->val)) {
            ans = root;
            return;
        }

        if(root->val < p->val && root->val < q->val){
            m(root->right,p,q);
        }

        if(root->val > p->val && root->val > q->val){
            m(root->left,p,q);
        }
 
        

    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        

        m( root,  p,  q);
        return ans;


        
    }
};
