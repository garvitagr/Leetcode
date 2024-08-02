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
    pair<TreeNode*,pair<TreeNode*,int>>find(TreeNode* root,int key){
        if(root==NULL)return {NULL,{NULL,0}};
        if(root->left and root->left->val==key)return {root,{root->left,0}};
        if(root->right and root->right->val==key)return {root,{root->right,1}};
        if(root->val==key)return {root,{root,0}};
        if(root->val>key)return find(root->left,key);
        else return find(root->right,key);
    }

    void findchildren(TreeNode* root,vector<int>&childnodes){
        if(root==NULL)return;
        findchildren(root->left,childnodes);
        childnodes.push_back(root->val);
        findchildren(root->right,childnodes);
    }

    TreeNode* createbst(vector<int>&childnodes,int st,int end){
        if(st>end)return NULL;
        int mid=(st+end)/2;
        TreeNode* root=new TreeNode(childnodes[mid]);
        root->left=createbst(childnodes,st,mid-1);
        root->right=createbst(childnodes,mid+1,end);
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)return NULL;
        if(root->val==key and !root->left and !root->right)return NULL;
        if(root->val==key and root->left and !root->right)return root->left;
        if(root->val==key and root->right and !root->left)return root->right;
        pair<TreeNode*,pair<TreeNode*,int>>deletenode={NULL,{NULL,0}};
        deletenode=find(root,key);//parent of deleted node, {deleted node,left/right};
        
        if(deletenode.first==NULL)return root;
        vector<int>childnodes;
        findchildren(deletenode.second.first->left,childnodes);
        findchildren(deletenode.second.first->right,childnodes);
        sort(childnodes.begin(),childnodes.end());

        int n=childnodes.size();
        if(n==0){
            if(deletenode.second.second==0)deletenode.first->left=NULL;
            else deletenode.first->right=NULL;
            return root;
        }

       TreeNode* rootdelsubtree=new TreeNode(childnodes[n/2]);
       rootdelsubtree->left=createbst(childnodes,0,n/2 -1);
       rootdelsubtree->right=createbst(childnodes,n/2 +1,n-1);

       if(root->val==key)return rootdelsubtree;

    if(deletenode.second.second==0)deletenode.first->left=rootdelsubtree;
    else deletenode.first->right=rootdelsubtree;
    
    return root;
    
    }
};