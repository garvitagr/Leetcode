class Solution {
public:
    int find(int curtime,int time,int change){
        int times=curtime/change;
        if(times&1){
            int rem=change*(times+1)-curtime;
            return rem+curtime+time;
        }
        return curtime+time;
    }

    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>>adj(n+1);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>dist1(n+1,INT_MAX),dist2(n+1,INT_MAX);
        set<pair<int,int>>st;
        st.insert({0,1});     
        dist1[1]=0;
        vector<int>visited(n+1,0);

        while(!st.empty()){
            auto pr=*st.begin();
            st.erase(pr);
            int node=pr.second;
            int curtime=pr.first;
   
            int nexttime=find(curtime,time,change);
            visited[node]++;
           
            if(visited[node]==2 and node==n)return dist2[n];

            for(auto nbr:adj[node]){
                if(dist1[nbr]>nexttime){
                    dist2[nbr]=dist1[nbr];
                    dist1[nbr]=nexttime;
                    st.insert({nexttime,nbr});
                }
                else if(dist2[nbr]>nexttime and nexttime!=dist1[nbr]){
                    dist2[nbr]=nexttime;
                    st.insert({nexttime,nbr});
                }
            }

        }
        return dist2[n];
    }   
};