class Solution {
public:
    bool dfs(int i,int j,vector<vector<int>>&grid1,vector<vector<int>>&grid2,vector<vector<int>>&visited){
        visited[i][j]=1;
        bool add=true;
        if(!grid1[i][j])add=false;
        int col[4]={-1,0,1,0};
        int row[4]={0,1,0,-1};
        for(int ind=0;ind<4;ind++){
            int newrow=i+row[ind];
            int newcol=j+col[ind];
            if(newrow>=0 and newrow<grid1.size() and newcol>=0 and newcol<grid1[0].size()){
                if(!visited[newrow][newcol] and grid2[newrow][newcol]){
                    add&=dfs(newrow,newcol,grid1,grid2,visited);
                }
            }
        }
        return add;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int i,j,n=grid1.size(),m=grid1[0].size(),ans=0;
        vector<vector<int>>visited(n,vector<int>(m,0));


        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(!visited[i][j] and grid1[i][j] and grid2[i][j]){
                    bool add=dfs(i,j,grid1,grid2,visited);
                    if(add)ans++;
                }
            }
        }
        return ans;
    }
};