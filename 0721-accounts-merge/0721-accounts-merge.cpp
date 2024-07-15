
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string,int>mp;
        DSU link(accounts.size());
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                if(mp.find(accounts[i][j])!=mp.end())link.Union(i,mp[accounts[i][j]]);
                else mp[accounts[i][j]]=i;
            }
        }

        vector<vector<string>>ans(accounts.size()),result;
        for(auto it:mp){
            ans[link.find(it.second)].push_back(it.first);
        }
        for(int i=0;i<ans.size();i++){
            auto it=ans[i];
            if(it.size()==0)continue;
            it.push_back(accounts[i][0]);
            reverse(it.begin(),it.end());
            sort(it.begin()+1,it.end());
            result.push_back(it);
        }

        return result;
    }
};