class TrieNode{
    public:
    char value;
    TrieNode* children[26];
    bool isTerminal;
    int index;
    int size;
    

    TrieNode(char val){
      this->value=val;
      for(int i=0;i<26;i++){
        children[i]=NULL;
      }
      this->isTerminal=false;
      this->index=-1;
      this->size=0;
    }
};

void insertWord(TrieNode* root,string &word,int ind, int itr,int size){
  if(word.size()==itr){
    root->isTerminal=true;
    root->index=ind;
    root->size=size;
    return;
  }

  char ch=word[itr];
  int index=ch-'a';
  if(root->children[index] ==NULL){
    root->children[index]=new TrieNode(ch);
  }
  size++;
  insertWord(root->children[index],word,ind, itr+1,size);
}
bool search(TrieNode* root,string &word,int itr){
   if(word.size()==itr){
      return root->isTerminal;
   }
   char ch=word[itr];
   int index=ch-'a';
   if(root->children[index]==NULL)return false;
   return search(root->children[index],word,itr+1);
}

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        int i,j;
        TrieNode* root=new TrieNode('-');
        for(i=0;i<dictionary.size();i++){
            insertWord(root,dictionary[i],i,0,0);
        }

        vector<string>words;
        string s="",ans="";
        for(i=0;i<sentence.size();i++){
            if(sentence[i]>='a' and sentence[i]<='z')s+=sentence[i];
            else words.push_back(s),s="";
        }
        words.push_back(s);
        for(i=0;i<words.size();i++){
            s="";
            for(j=0;j<words[i].size();j++){
                s+=words[i][j];
                if(search(root,s,0)){
                    break;
                }
            }
            ans+=s;
            ans+=" ";
        }
        ans.pop_back();
        return ans;
    }
};