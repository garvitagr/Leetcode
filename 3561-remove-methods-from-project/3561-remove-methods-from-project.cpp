class Solution {
public:
    void dfs(int k,vector<int>&visited,vector<vector<int>>&adj,set<int>&susp){
        visited[k]=1;
        susp.insert(k);
        for(auto it:adj[k]){
            if(!visited[it])dfs(it,visited,adj,susp);
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& inv) {
        set<int>susp;
        vector<vector<int>>adj(n);
        vector<vector<int>>in(n);
        for(int i=0;i<inv.size();i++){
            int u=inv[i][0];
            int v=inv[i][1];
            adj[u].emplace_back(v);
            in[v].emplace_back(u);
        }
        vector<int>visited(n,0);
        dfs(k,visited,adj,susp);
        map<int,int>mp;
        vector<int>ans;
        for(auto it:susp){
            bool flag=1;
            for(int i=0;i<in[it].size();i++){
                int val=in[it][i];
                if(susp.find(val)==susp.end())flag=false;
            }
            if(flag==false){
                for(int i=0;i<n;i++)ans.push_back(i);
                return ans;
            }
        }
        for(int i=0;i<n;i++){
            if(susp.find(i)==susp.end())ans.push_back(i);
        }
        return ans;
    }
};