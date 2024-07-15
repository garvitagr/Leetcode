class DSU{
public:     
   vector<int>parent;
   vector<int>rank;
   int edge=0;

   DSU(int n){
        parent.resize(n+1);
        for(int i=1;i<=n;i++)parent[i]=i;
        rank.resize(n+1,0);
   }

int find(int x){
   if(x==parent[x])return x;
   return parent[x]=find(parent[x]);
}

void Union(int x,int y){

    int x_parent=find(x);
    int y_parent=find(y);

    if(x_parent==y_parent)return;
    edge++;

    if(rank[x_parent]>rank[y_parent]){
        parent[y_parent]=x_parent;
    }
    else if(rank[x_parent]<rank[y_parent]){
        parent[x_parent]=y_parent;
    }
    else{
        parent[x_parent]=y_parent;
        rank[y_parent]++;
    }
}

};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU alice(n);
        DSU bob(n);
        sort(edges.rbegin(),edges.rend());
        int remove=0;
        for(int i=0;i<edges.size();i++){
            bool flag=false;
            if(edges[i][0]==3){
                if(alice.find(edges[i][1])!=alice.find(edges[i][2]))flag=true;
                if(bob.find(edges[i][1])!=bob.find(edges[i][2]))flag=true;
                alice.Union(edges[i][1],edges[i][2]);
                bob.Union(edges[i][1],edges[i][2]);
            }
            else if(edges[i][0]==1){
                if(alice.find(edges[i][1])!=alice.find(edges[i][2]))flag=true;
                alice.Union(edges[i][1],edges[i][2]);
            }
            else{
                if(bob.find(edges[i][1])!=bob.find(edges[i][2]))flag=true;
                bob.Union(edges[i][1],edges[i][2]);
            }
            if(!flag)remove++;
        }
        if(alice.edge!=n-1 or bob.edge!=n-1)return -1;
        return remove;
    }
};