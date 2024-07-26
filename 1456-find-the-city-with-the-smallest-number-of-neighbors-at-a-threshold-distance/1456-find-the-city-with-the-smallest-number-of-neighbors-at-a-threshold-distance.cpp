class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dst) {
        vector<vector<pair<int,int>>>adj(n);
        int i;
        for(i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        map<int,int>mp;
        for(int i=0;i<n;i++){
            set<pair<int,int>>st;
            vector<int>distance(n,INT_MAX);
            distance[i]=0;
            for(auto it:adj[i]){
                st.insert({it.second,it.first});
            }
            while(!st.empty()){
                auto it=*st.begin();
                int dist=it.first;
                int node=it.second;
                st.erase(it);
                distance[node]=min(dist,distance[node]);
                for(auto nbr:adj[node]){
                    if(distance[nbr.first]>nbr.second+dist)st.insert({nbr.second+dist,nbr.first});
                }
            }
            
            for(int j=0;j<n;j++){
                if(j==i)continue;
                if(distance[j]<=dst)mp[i]++;
            }
        }
        int times=INT_MAX,ans;
        for(int i=0;i<n;i++){
            if(mp[i]<=times){
                times=mp[i];
                ans=i;
            }
        }
        return ans;
    }
};