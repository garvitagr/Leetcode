class TrieNode{
public:
    char value;
    TrieNode* children[26];
    bool isTerminal;
    

    TrieNode(char val){
      this->value=val;
      for(int i=0;i<26;i++){
        children[i]=NULL;
      }
      this->isTerminal=false;
    }
};


class Trie {
public:
    TrieNode* root;
    Trie() {
        root=new TrieNode('-');
    }
    
    void insert(string word) {
        int i=0;
        TrieNode* curroot=root;
        for(i=0;i<word.size();i++){
            int index=word[i]-'a';
            if(curroot->children[index]==NULL)curroot->children[index]=new TrieNode(word[i]);
            curroot=curroot->children[index];
        }
        curroot->isTerminal=true;
    }
    
    bool search(string word) {
        int i;
        TrieNode* curroot=root;
        for(i=0;i<word.size();i++){
            int index=word[i]-'a';
            if(curroot->children[index]==nullptr)return false;
            else curroot=curroot->children[index];
        }
        return curroot->isTerminal;
    }
    
    bool startsWith(string prefix) {
        int i;
        TrieNode* curroot=root;
        for(i=0;i<prefix.size();i++){
            int index=prefix[i]-'a';
            if(curroot->children[index]==NULL)return false;
            else curroot=curroot->children[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */