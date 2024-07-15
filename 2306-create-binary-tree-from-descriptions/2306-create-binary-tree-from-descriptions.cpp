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
    void create(TreeNode* root,map<int,pair<int,int>>&node){
        if(node[root->val].first){
            TreeNode* newnode=new TreeNode(node[root->val].first);
            root->left=newnode;
            create(root->left,node);
        }
        if(node[root->val].second){
            TreeNode* newnode=new TreeNode(node[root->val].second);
            root->right=newnode;
            create(root->right,node);
        }
    }

    TreeNode* createBinaryTree(vector<vector<int>>& desc) {
        map<int,pair<int,int>>node;
        map<int,int>cannotroot;
        int rootnode;
        for(int i=0;i<desc.size();i++){
            if(desc[i][2]==1)node[desc[i][0]].first=desc[i][1];
            if(desc[i][2]==0)node[desc[i][0]].second=desc[i][1];
            cannotroot[desc[i][1]]++;
        }
        for(int i=0;i<desc.size();i++){
            if(!cannotroot[desc[i][0]])rootnode=desc[i][0];
        }
        TreeNode* root=new TreeNode(rootnode);
        create(root,node);
        return root;
    }
};