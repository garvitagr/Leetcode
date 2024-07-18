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
    void findleafs(TreeNode* root,unordered_map<TreeNode*,int>&leafs){
        if(root==NULL)return;
        findleafs(root->left,leafs);
        findleafs(root->right,leafs);
        if(root->left==NULL and root->right==NULL)leafs[root]++;
    }

    void traverse(TreeNode* root,unordered_map<TreeNode*,vector<TreeNode*>>&adj){
        if(root==NULL)return;
        if(root->right==NULL and root->left==NULL)return;
        if(root->right){
            adj[root].push_back(root->right);
            adj[root->right].push_back(root);
            traverse(root->right,adj);
        }
        if(root->left){
            adj[root].push_back(root->left);
            adj[root->left].push_back(root);
            traverse(root->left,adj);
        }
    }

    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*,int>leafs;
        findleafs(root,leafs);
        int ans=0;
        unordered_map<TreeNode*,vector<TreeNode*>>adj;
        traverse(root,adj);
        for(auto it:leafs){
            queue<pair<TreeNode*,int>>q;
            q.push({it.first,0});
            unordered_map<TreeNode*,int>visited;
            while(!q.empty()){
                TreeNode* curnode=q.front().first;
                visited[curnode]=1;
                int dist=q.front().second;
                if(dist>distance)break;
                if(leafs.find(curnode)!=leafs.end() and it.first!=curnode)ans++;
                q.pop();
                for(auto nbr:adj[curnode]){
                    if(visited.find(nbr)==visited.end())q.push({nbr,dist+1});
                }
            }
        }
        return ans/2;
    }
};