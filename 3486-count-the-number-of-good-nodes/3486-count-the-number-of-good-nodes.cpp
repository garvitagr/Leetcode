class kundli{
    public:

    int size;

    kundli(int size){
        this->size=size;
    }
};

class Solution {
public:
    int ans=0;

    kundli* dfs(int node,vector<vector<int>>&adj,vector<int>&visited){
        visited[node]=1;
        bool isleaf=true;
        for(auto it:adj[node]){
            if(!visited[it]){
                isleaf=false;
                break;
            }
        }
        if(isleaf){
            ans++;
            return new kundli(1);
        }

        int count=0;
        bool add=true;
        bool flag=false;
        int ct=0;

        for(auto it:adj[node]){
            if(visited[it])continue;
            kundli* child=dfs(it,adj,visited);
            count+=child->size;
            if(!flag){
                flag=true;ct=child->size;
            }
            else{
                add&=(ct==child->size);
            }
        }
        if(add)ans++;
        // cout<<node<<" "<<count<<" "<<add<<endl;
        return new kundli(count+1);
    }

    int countGoodNodes(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vector<vector<int>>adj(n);
        vector<int>visited(n,0);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        visited[0]=1;
        dfs(0,adj,visited);
        return ans;
    }
};