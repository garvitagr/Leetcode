class Solution {
public:

    bool pos(vector<vector<char>>& board, int i,int j,int k ){
        int col,row,ind;
        row=(i/3)*3;
        col=(j/3)*3;
        char num='0'+k;

        for(ind=0;ind<9;ind++){
            if(board[ind][j]==num)return false;
        }
        for(ind=0;ind<9;ind++){
            if(board[i][ind]==num)return false;
        }
        for(i=row;i<row+3;i++){
            for(j=col;j<col+3;j++){
                if(board[i][j]==num)return false;
            }
        }
        return true;
    }


    bool recur(vector<vector<char>>& board,int i,int j){
        // base
        if(i>=8 and j>8){
            return true;
        }
    
        if(j>8){
            i++;j=0;
           return recur(board,i,j);
        }
        if(board[i][j]!='.'){
            j++;
            return recur(board,i,j);    
        }


        int k;
        for(k=1;k<=9;k++){
            if( pos(board,i,j,k)  ){
                char ch='0'+k;
                board[i][j]=(ch);
               if(recur(board,i,j+1)){
                   return true;
               }
               board[i][j]='.';
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        recur(board,0,0);
    }
};