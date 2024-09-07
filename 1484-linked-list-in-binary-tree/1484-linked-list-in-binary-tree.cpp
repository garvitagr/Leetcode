/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool dfs(vector<int>&v,TreeNode* root,int ind){
        if(ind==v.size())return true;
        if(root==NULL)return false;
        if(root->val==v[ind]){
            bool left=dfs(v,root->left,ind+1);
            bool right=dfs(v,root->right,ind+1);
            return left||right;
        }
        return false;
    }
    bool check(vector<int>&v,TreeNode* root){
        if(root==NULL)return false;
        return dfs(v,root,0)||check(v,root->left)||check(v,root->right);
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        if(head==NULL)return true;
        if(root==NULL)return false;
        ListNode* temp=head;
        vector<int>v;
        while(temp){
            v.push_back(temp->val);
            temp=temp->next;
        }
        return check(v,root);
    }
};