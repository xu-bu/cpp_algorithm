struct TreeNode{
    int val;
    TreeNode *left,*right;
    TreeNode():val(0),left(nullptr),right(nullptr){};
    TreeNode(int x):val(x),left(nullptr),right(nullptr){};
    TreeNode(int x,TreeNode *l,TreeNode *r):val(x),left(l),right(r){};
};

class Solution {
public:
    int ans=0;
    void preOrder(TreeNode *root,int low,int high){
        if(root== nullptr){
            return;
        }
        if(root->val<=high&&root->val>=low){
            ans+=root->val;
        }
        preOrder(root->left,low,high);
        preOrder(root->right,low,high);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        preOrder(root,low,high);
        return ans;
    }
};