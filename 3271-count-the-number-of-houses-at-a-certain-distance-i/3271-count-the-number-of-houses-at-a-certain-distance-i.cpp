class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<int>ans(n,0);
        vector<int>adj[n+1];
        int i;
        for(i=1;i<n;i++){
            adj[i].push_back(i+1);
            adj[i+1].push_back(i);
        }
        if(x!=y){
            adj[x].push_back(y);
            adj[y].push_back(x);
        }        

        for(i=1;i<=n;i++){
            queue<pair<int,int>>q;
            vector<int>visited(n+1,0);
            visited[i]=1;
            q.push({i,0});
            while(!q.empty()){
                int dist=q.front().second;
                int src=q.front().first;
                q.pop();
                for(auto nbr:adj[src]){
                    if(!visited[nbr]){
                        q.push({nbr,dist+1});
                        ans[dist]++;
                        visited[nbr]=1;
                    }                    
                }
            }
        }

        return ans;
    }
};