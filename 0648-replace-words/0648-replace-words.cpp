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
        if(root->children[index]==nullptr)root->children[index]=new TrieNode(word[i]);
        root=root->children[index];
    }
    root->isTerminal=true;
}

string findprefix(TrieNode* root,string word){
    int i,n=word.size();
    for(i=0;i<word.size();i++){
        int index=word[i]-'a';
        if(root->children[index]==nullptr)return word;
        root=root->children[index];
        if(root->isTerminal)return word.substr(0,i+1);
    }
    return word;
}


class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        TrieNode* root=new TrieNode('-');
        for(int i=0;i<dictionary.size();i++){
            insertWord(root,dictionary[i]);
        }
        string word="",ans="";
        for(int i=0;i<sentence.size();i++){
            if(sentence[i]==' '){
                string prefix=findprefix(root,word);
                ans+=prefix+" ";
                word="";
                continue;
            }
            word+=sentence[i];
            if(i==sentence.size()-1){
                string prefix=findprefix(root,word);
                ans+=prefix;
                word="";
            }
        }
        return ans;
    }
};