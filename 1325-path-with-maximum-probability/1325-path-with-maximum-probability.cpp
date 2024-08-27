class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& prob, int start, int end) {
        vector<vector<pair<int,double>>>adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(make_pair(v,prob[i]));
            adj[v].push_back(make_pair(u,prob[i]));
        }
        set<pair<double,int>>st;
        vector<double>dist(n,0);
        dist[start]=1;
        st.insert(make_pair(1,start));

        while(!st.empty()){
            auto it=*st.rbegin();
            int node=it.second;
            double p=it.first;
            dist[node]=max(dist[node],p);
            st.erase(it);

            for(auto it:adj[node]){
                if(dist[it.first]<p*it.second){
                    st.insert(make_pair(p*it.second,it.first));
                }
            } 
        }
        return dist[end];
    }
};