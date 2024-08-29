class DSU{
public:
   vector<int>parent;
   vector<int>rank;

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
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size(),ans=0;
        DSU* gang=new DSU(n);

        for(int i=0;i<stones.size();i++){
            for(int j=i+1;j<stones.size();j++){
                if(stones[i][0]==stones[j][0] or stones[i][1]==stones[j][1])gang->Union(i,j);
            }
        }
        for(int i=0;i<n;i++){
            if(gang->parent[i]==i)ans++;
        }
        return n-ans;
    }
};