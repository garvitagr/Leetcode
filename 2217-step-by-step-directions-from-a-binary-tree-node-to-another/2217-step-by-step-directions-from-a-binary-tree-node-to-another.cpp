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
    TreeNode* findlca(TreeNode* root,int x,int y){
        if(root==NULL)return NULL;
        if(root->val==x or root->val==y)return root;
        TreeNode* left=findlca(root->left,x,y);
        TreeNode* right=findlca(root->right,x,y);
        if(left!=NULL and right!=NULL)return root;
        if(left)return left;
        else return right;
    }
    void path(string &addr,TreeNode* root,int startvalue,string &steps){
        if(root==NULL)return;
        if(root->val==startvalue){
            steps=addr;
            return;
        }
        // go left;
        addr.push_back('L');
        path(addr,root->left,startvalue,steps);
        addr.pop_back();
        // go right;
        addr.push_back('R');
        path(addr,root->right,startvalue,steps);
        addr.pop_back();
    }

    string getDirections(TreeNode* root, int startvalue, int destvalue) {
        TreeNode* lca=findlca(root,startvalue,destvalue);
        string start="",ans="",end="",temp="";
        path(temp,lca,startvalue,start);
        path(temp,lca,destvalue,end);

        for(int i=0;i<start.size();i++)start[i]='U';
        ans+=start;
        ans+=end;
        return ans;
    }
};