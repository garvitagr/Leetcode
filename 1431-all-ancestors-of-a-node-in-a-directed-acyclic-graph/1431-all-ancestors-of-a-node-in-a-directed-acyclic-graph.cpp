class Solution {
public:
    void dfs(int src,vector<vector<int>>&adj,vector<vector<int>>&ans,vector<int>&visited,int node){
        if(src!=node)ans[src].push_back(node);
        for(auto nbr:adj[src]){
            if(!visited[nbr]){
                visited[nbr]=1;
                dfs(nbr,adj,ans,visited,node);
            }
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n),ans(n);
        int i;
        for(i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        for(i=0;i<n;i++){
            vector<int>visited(n,0);
            visited[i]=1;
            dfs(i,adj,ans,visited,i);
        }
        return ans;
    }
};