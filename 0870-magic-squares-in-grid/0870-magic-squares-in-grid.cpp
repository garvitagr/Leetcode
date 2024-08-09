class Solution {
public:
    bool check(int r,int c,vector<vector<int>>&grid){
        // row wise
        set<int>st;
        for(int i=r;i<r+3;i++){
            int sum=0;
            for(int j=c;j<c+3;j++){
                sum+=grid[i][j];
            }
            st.insert(sum);
        }
        // col wise
        for(int j=c;j<c+3;j++){
            int sum=0;
            for(int i=r;i<r+3;i++){
                sum+=grid[i][j];
            }
            st.insert(sum);
        }
        // diag
        int sum=0;
        sum+=grid[r][c]+grid[r+1][c+1]+grid[r+2][c+2];
        st.insert(sum);
        sum=0;
        sum+=grid[r][c+2]+grid[r+1][c+1]+grid[r+2][c];
        st.insert(sum);
        
        vector<int>vals;
        for(int i=r;i<r+3;i++){
            for(int j=c;j<c+3;j++)vals.emplace_back(grid[i][j]);
        }
        sort(vals.begin(),vals.end());
        for(int i=0;i<9;i++)if(vals[i]!=i+1)return false;

        return st.size()==1;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int row=grid.size(),col=grid[0].size(),ans=0;
        for(int i=0;i<=row-3;i++){
            for(int j=0;j<=col-3;j++){
                ans+=check(i,j,grid);
            }
        }
        return ans;
    }
};