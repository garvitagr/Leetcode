class Solution {
public:
    void topologicalsort(vector<int>&topo,int k,vector<vector<int>>& Conditions){
        vector<int>indegree(k+1,0);
        vector<vector<int>>adj(k+1);
        for(int i=0;i<Conditions.size();i++){
            int x=Conditions[i][0];
            int y=Conditions[i][1];
            indegree[x]++;
            adj[y].push_back(x);
        }
        queue<int>q;
        for(int i=1;i<=k;i++){
            if(indegree[i]==0)q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto nbr:adj[node]){
                indegree[nbr]--;
                if(indegree[nbr]==0)q.push(nbr);
            }
        }
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int>rowtopo,coltopo;
        topologicalsort(rowtopo,k,rowConditions);
        topologicalsort(coltopo,k,colConditions);
        map<int,int>mp;
        vector<vector<int>>v(k,vector<int>(k,0));
        if(rowtopo.size()!=k)return {};
        if(coltopo.size()!=k)return {};
        reverse(rowtopo.begin(),rowtopo.end());
        reverse(coltopo.begin(),coltopo.end());
        for(int i=0;i<coltopo.size();i++){
            mp[coltopo[i]]=i;
        }
        
        for(int i=0;i<k;i++){
            int val=rowtopo[i];
            int column=mp[val];
            v[i][column]=val;
        }
        return v;     
    }
};