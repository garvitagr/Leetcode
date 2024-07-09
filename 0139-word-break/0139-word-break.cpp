class TrieNode{
public:    
    char value;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch){
        this->value=ch;
        for(int i=0;i<26;i++)this->children[i]=NULL;
        this->isTerminal=false;
    }
};

void insertWord(TrieNode* root,string word){
    int i,n=word.size();
    for(i=0;i<n;i++){
        int index=word[i]-'a';
        if(root->children[index]==NULL)root->children[index]=new TrieNode(word[i]);
        root=root->children[index];
    }
    root->isTerminal=true;
}

class Solution {
public:
    bool check(TrieNode* root,string word,int ind,vector<int>&dp){
        int i,n=word.size();
        if(ind==n)return true;
        if(dp[ind]!=-1)return dp[ind];
        TrieNode* curroot=root;
        
        for(i=ind;i<n;i++){
            int index=word[i]-'a';
            if(curroot->children[index]==NULL)return dp[ind]=false;
            curroot=curroot->children[index];
            if(curroot->isTerminal){
                bool start=check(root,word,i+1,dp);
                if(start)return dp[ind]=true;
            }
        }
        return dp[ind]=curroot->isTerminal;
    }


    bool wordBreak(string s, vector<string>& wordDict) {
        int i,n=wordDict.size();
        vector<int>dp(s.size()+1,-1);
        TrieNode* root=new TrieNode('-');
        for(i=0;i<n;i++){
            insertWord(root,wordDict[i]);
        }
        return check(root,s,0,dp);
    }
};