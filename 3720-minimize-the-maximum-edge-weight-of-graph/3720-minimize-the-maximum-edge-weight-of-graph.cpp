class Solution {
public:
    void dfs(vector<vector<pair<int,int>>>&adj,int curNode,vector<int>&vis,int maxiVal){
        vis[curNode]=1;
        for(auto it:adj[curNode]){
            int v=it.first;
            int w=it.second;
            if(w>maxiVal)continue;
            if(!vis[v])dfs(adj,v,vis,maxiVal);
        }
    }
    bool reachable(vector<vector<pair<int,int>>>&adj,int maxiVal){
        int n=adj.size();
        vector<int>vis(n,0);
        dfs(adj,0,vis,maxiVal);
        for(int i=0;i<n;i++){
            if(!vis[i])return false;
        }
        return true;
    }

    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            adj[v].push_back({u,w});
        }
        int low=1,high=1e9,ans=high;

        while(low<=high){
            int mid=(low+high)/2;
            if(reachable(adj,mid)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        if(ans==1e9)return -1;
        return ans;
    }
};