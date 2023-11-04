class Solution {
public:
        unordered_map<int,bool>row;
        unordered_map<int,bool>updig;
        unordered_map<int,bool>lowdig;
    
    void recur(vector<vector<int>>&board,int n,vector<vector<string>>&ans,int col){
        
        if(col>=n){
            int i,j;
            vector<string>temp;
            for(i=0;i<n;i++){
                string s;
                for(j=0;j<n;j++){
                    if(board[i][j]==1)s.push_back('Q');
                    else s.push_back('.');
                }
                temp.push_back(s);
            }
            ans.push_back(temp);
            return;
        }
        int i;
        
        for(i=0;i<n;i++){
            if(((row[i]==0) and (updig[col-i]==0) and (lowdig[col+i]==0) )){
                board[i][col]=1;
                row[i]=1;
                updig[col-i]=1;
                lowdig[col+i]=1;

                recur(board,n,ans,col+1);

                board[i][col]=0;
                row[i]=0;
                updig[col-i]=0;
                lowdig[col+i]=0;
                
            }
        }
    
        
    }


    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>>board(n,vector<int>(n,0));
        vector<vector<string>>ans;
        recur(board,n,ans,0);
        sort(ans.begin(),ans.end());
        return ans;
    }
};