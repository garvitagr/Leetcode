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
class FindElements {
public:
    void fillTree(TreeNode* root){
        if(root->left){
            root->left->val=root->val*2 +1;
            fillTree(root->left);
        }
        if(root->right){
            root->right->val=root->val*2 +2;
            fillTree(root->right);
        }
    }
    TreeNode* Root;
    FindElements(TreeNode* root) {
        Root=root;
        root->val=0;
        fillTree(root);
    }
    bool check(TreeNode* Root,int target){
        if(!Root)return false;
        if(Root->val==target)return true;
        return check(Root->left,target)||check(Root->right,target);
    }
    bool find(int target) {
        return check(Root,target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */