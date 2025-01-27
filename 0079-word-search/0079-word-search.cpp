class Solution {
public:
    bool make(int i,int j,string word,vector<vector<char>>& board,int row,int col,int ind,map<pair<int,int>,int>&mp){
        if(ind==word.size())return true;

        bool ans1=false,ans2=false,ans3=false,ans4=false;
        
        if(i+1<row and mp[{i+1,j}]==0 and word[ind]==board[i+1][j]){
            mp[{i+1,j}]++;
            ans1=make(i+1,j,word,board,row,col,ind+1,mp);
            mp[{i+1,j}]--;
        }
        if(i-1>=0 and mp[{i-1,j}]==0 and word[ind]==board[i-1][j]){
            mp[{i-1,j}]++;
            ans2=make(i-1,j,word,board,row,col,ind+1,mp);
            mp[{i-1,j}]--;
        }
        if(j+1<col and mp[{i,j+1}]==0 and word[ind]==board[i][j+1]){
            mp[{i,j+1}]++;
            ans3=make(i,j+1,word,board,row,col,ind+1,mp);
            mp[{i,j+1}]--;
        }
        if(j-1>=0 and mp[{i,j-1}]==0 and word[ind]==board[i][j-1]){
            mp[{i,j-1}]++;
            ans4=make(i,j-1,word,board,row,col,ind+1,mp);
            mp[{i,j-1}]--;
        }

        return (ans1||ans2||ans3||ans4);
    }

    bool exist(vector<vector<char>>& board, string word) {
        int i,j,row=board.size(),col=board[0].size();

        for(i=0;i<row;i++){
            for(j=0;j<col;j++){
                if(word[0]==board[i][j]){
                    map< pair<int,int>,int>mp;
                    mp[{i,j}]++;
                    if(make(i,j,word,board,row,col,1,mp))return true;
                }
            }
        }
        return false;
    }
};