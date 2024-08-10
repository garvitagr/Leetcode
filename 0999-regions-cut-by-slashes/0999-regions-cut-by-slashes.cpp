class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>&visited,vector<vector<int>>&v){
        visited[i][j]=1;
        vector<int>up={1,0,-1,0};
        vector<int>left={0,-1,0,1};
        
        for(int k=0;k<4;k++){
            int row=i+up[k];
            int col=j+left[k];

            if(row>=0 and row<v.size() and col>=0 and col<v[0].size() and !visited[row][col] and v[row][col]==0)dfs(row,col,visited,v);
        }
    }

    int regionsBySlashes(vector<string>& grid) {
        int rows=grid.size(),cols=grid[0].size(),ct=0;
        vector<vector<int>>v(rows*3,vector<int>(cols*3,0));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]=='/'){
                    v[3*i][3*j +2]=1;
                    v[3*i +1][3*j +1]=1;
                    v[3*i +2][3*j]=1;
                }
                else if(grid[i][j]=='\\'){
                    v[3*i][3*j]=1;
                    v[3*i +1][3*j +1]=1;
                    v[3*i +2][3*j +2]=1;
                }
            }
        }
        vector<vector<int>>visited(rows*3,vector<int>(cols*3,0));
        for(int i=0;i<rows*3;i++){
            for(int j=0;j<cols*3;j++){
                if(!visited[i][j] and v[i][j]==0){
                    ct++;dfs(i,j,visited,v);
                }
            }
        }
        return ct;
    }
};