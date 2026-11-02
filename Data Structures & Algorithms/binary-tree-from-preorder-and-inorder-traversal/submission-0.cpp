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

    int rootIndex(int val, vector<int>& inorder, int s, int e){

        for(int i = s; i <= e; i++){
            if(inorder[i] == val){
                return i;
            }
        }

        return -1;

    }


    TreeNode* get(vector<int>& preorder, vector<int>& inorder, int s, int e, int &preOrderIndex){

        if(s > e){
            return NULL;
        }

        int val = preorder[preOrderIndex++];

        int index = rootIndex(val,inorder,s,e);

        TreeNode* root = new TreeNode(val);

        if(s==e){
            return root;
        }

        if(index!= -1){
            root->left = get(preorder, inorder,s,index-1,preOrderIndex);
            root->right = get(preorder, inorder,index+1,e,preOrderIndex);
        }

        return root;

    }
    

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        int n = preorder.size(), preOrderIndex=0;

        TreeNode* res = get(preorder, inorder,0,n-1, preOrderIndex);

        return res;
        
    }
};
