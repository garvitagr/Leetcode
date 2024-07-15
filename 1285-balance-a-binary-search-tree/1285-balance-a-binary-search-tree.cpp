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
    void inorder(TreeNode* root,vector<int>&v){
        if(root==NULL)return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    TreeNode* build(int i,int j,vector<int>&v){
        if(i==j){
            TreeNode* newnode=new TreeNode(v[i]);
            return newnode;
        }
        if(i>j)return NULL;
        int mid=(i+j)/2;
        TreeNode* newroot=new TreeNode(v[mid]);
        newroot->left=build(i,mid-1,v);
        newroot->right=build(mid+1,j,v);
        return newroot;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int>v;
        inorder(root,v);
        int n=v.size();
        int i=0,j=n-1;
        int mid=(i+j)/2;
        TreeNode* newroot=new TreeNode(v[mid]);
        newroot->left=build(i,mid-1,v);
        newroot->right=build(mid+1,j,v);
        return newroot;
    }
};