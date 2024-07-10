class TrieNode{
public:
    char value;
    TrieNode* children[26];
    int index;

    TrieNode(char ch){
        this->value=ch;
        for(int i=0;i<26;i++)this->children[i]=NULL;
        this->index=-1;
    }
};

void insertWord(TrieNode* root,string word,int ind) {
    int i=0;
    reverse(word.begin(),word.end());
    TrieNode* curroot=root;
    for(i=0;i<word.size();i++){
        int index=word[i]-'a';
        if(curroot->children[index]==NULL)curroot->children[index]=new TrieNode(word[i]);
        curroot=curroot->children[index];
    }
    curroot->index=ind;
}


class Solution {
public:
    bool is_palindrome(string s){
        int i=0,j=s.size()-1;
        while(i<=j){
            if(s[i]!=s[j])return false;
            i++;j--;
        }
        return true;
    }

    void find(TrieNode* root,vector<int>&temp,string &s){
        if(root->index != -1){
            if(is_palindrome(s))temp.push_back(root->index);
        }
        
        for(int i=0;i<26;i++){
            if(root->children[i] != NULL){
                char ch='a'+i;
                s.push_back(ch);
                find(root->children[i],temp,s);
                s.pop_back();
            }
        }
    }

    void search(TrieNode* root,string &word,vector<int>&temp){
        int i,n=word.size();
        TrieNode* curroot=root;
        for(i=0;i<n;i++){
            if(curroot->index != -1){
                string remainword=word.substr(i,n-i);
                if(is_palindrome(remainword))temp.push_back(curroot->index);
            }
            int wordind=word[i]-'a';
            if(curroot->children[wordind])curroot=curroot->children[wordind];
            else return;
        }
        string s="";
        find(curroot,temp,s);
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        TrieNode* root=new TrieNode('-');
        vector<vector<int>>ans;
        
        int i,n=words.size();
        for(i=0;i<n;i++){
            insertWord(root,words[i],i);
        }
        cout<<root->index;

        for(i=0;i<n;i++){
            vector<int>temp;
            search(root,words[i],temp);
            for(auto it:temp){
                if(it!=i)ans.push_back({i,it});
            }
        }
        return ans;
    }
};