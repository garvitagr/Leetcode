class TrieNode{
public:
    char value;
    TrieNode* children[26];
    bool isTerminal;
    long long cost;
    

    TrieNode(char val){
      this->value=val;
      for(int i=0;i<26;i++){
        children[i]=NULL;
      }
      this->isTerminal=false;
      this->cost=INT_MAX;
    }
};

void insertWord(TrieNode* root,string word,long long cost) {
    int i=0;
    for(i=0;i<word.size();i++){
        int index=word[i]-'a';
        if(root->children[index]==NULL)root->children[index]=new TrieNode(word[i]);
        root=root->children[index];
    }
    root->cost=min(root->cost,cost);
    root->isTerminal=true;
}



class Solution {
public:

    int mincost(TrieNode*root,string &target,int ind,vector<int>&dp){
        if(ind==target.size())return 0;
        int i,n=target.size();
        if(dp[ind]!=-1)return dp[ind];
        TrieNode* curroot=root;
        long long ans=INT_MAX;
        for(i=ind;i<n;i++){
            int index=target[i]-'a';
            if(curroot->children[index])curroot=curroot->children[index];
            else break;
            if(curroot->isTerminal){
                long long temp= curroot->cost + mincost(root,target,i+1,dp);
                ans=min(ans,temp);
            }         
        }
        return dp[ind]=ans;
    }

    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        TrieNode* root=new TrieNode('-');
        for(int i=0;i<words.size();i++){
            insertWord(root,words[i],costs[i]);
        }
        vector<int>dp(target.size()+1,-1);
        long long ans=mincost(root,target,0,dp);
        if(ans>=INT_MAX)return -1;
        return ans;
    }
};