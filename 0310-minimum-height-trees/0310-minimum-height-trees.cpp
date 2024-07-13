class Solution {
public:

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)return {0};
        if(n==2)return {0,1};
        unordered_map<int,int>degree;
        vector<vector<int>>adjlist(n);
        for(int i=0;i<edges.size();i++){
            degree[edges[i][0]]++;
            degree[edges[i][1]]++;
            adjlist[edges[i][0]].push_back(edges[i][1]);
            adjlist[edges[i][1]].push_back(edges[i][0]);
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(degree[i]==1)q.push(i);
        }

        while(n>2){
            int size=q.size();
            n-=size;
            while(size--){
                int node=q.front();
                q.pop();
                for(auto nbr:adjlist[node]){
                    degree[nbr]--;
                    if(degree[nbr]==1)q.push(nbr);
                }
            }
        }

        vector<int>ans;
        ans.push_back(q.front());
        q.pop();
        if(!q.empty())ans.push_back(q.front()),q.pop();

        return ans;        
    }
};