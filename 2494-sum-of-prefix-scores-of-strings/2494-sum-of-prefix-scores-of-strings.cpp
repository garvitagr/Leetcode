class TrieNode{
public:
    char value;
    TrieNode* children[26];
    int count=0;

    TrieNode(char ch){
        this->value=ch;
        for(int i=0;i<26;i++){
            this->children[i]=NULL;
        }
    }
};

void insertword(TrieNode* trie,string word){
    int i,n=word.size();
    for(int i=0;i<n;i++){
        int index=word[i]-'a';
        if(trie->children[index]!=NULL){
            trie=trie->children[index];
        }
        else{
            TrieNode* newchildren=new TrieNode(word[i]);
            trie->children[index]=newchildren;
            trie=trie->children[index];
        }
        trie->count++;
    }
}

int traverse(string word,TrieNode* trie){
    int ct=0;
    for(int i=0;i<word.size();i++){
        int index=word[i]-'a';
        trie=trie->children[index];
        ct+=trie->count;
    }
    return ct;
}

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        TrieNode* trie=new TrieNode('-');
        for(int i=0;i<words.size();i++){
            insertword(trie,words[i]);
        }
        vector<int>ans(words.size(),0);
        for(int i=0;i<words.size();i++){
            ans[i]=traverse(words[i],trie);
        }
        return ans;
    }
};