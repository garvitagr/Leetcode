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
    TreeNode* deletenode(TreeNode* root,vector<TreeNode*>&ans,unordered_set<int>&st){
        if(root==NULL)return nullptr;
        root->left=deletenode(root->left,ans,st);
        root->right=deletenode(root->right,ans,st);

        if(st.find(root->val)!=st.end()){
            if(root->left)ans.push_back(root->left);
            if(root->right)ans.push_back(root->right);
            return NULL;
        }
        else return root;
        
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*>ans;
        unordered_set<int>st(to_delete.begin(),to_delete.end());
        root=deletenode(root,ans,st);
        if(root)ans.push_back(root);
        return ans;
    }
};