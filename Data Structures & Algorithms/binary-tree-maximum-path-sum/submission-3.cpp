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
            return 0;
        }


        int sum1 = INT_MIN, sum2 = INT_MIN;
        int l =  m(root->left, maxd);
        int r =  m(root->right, maxd);


        sum1 = max(sum1,l+r+root->val);

        sum2 = max(sum2, max(max(l,r)+root->val,root->val));


        maxd = max(maxd, max(sum1,sum2));


        return sum2;

    }

    int maxPathSum(TreeNode* root) {

        int maxd = INT_MIN;

        m(root, maxd);


        return maxd;

    }
};
