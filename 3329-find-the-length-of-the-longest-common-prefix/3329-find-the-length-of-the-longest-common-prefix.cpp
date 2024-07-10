class TrieNode{
public:
    char value;
    TrieNode* children[10];
    bool is_Terminal;
    
    TrieNode(char ch){
        this->value=ch;
        for(int i=0;i<10;i++)this->children[i]=nullptr;
        this->is_Terminal=false;
    }
};

void insert(TrieNode* root,int num){
    string word=to_string(num);
    int i,n=word.size();
    
    for(i=0;i<n;i++){
        int index=word[i]-'0';
        if(root->children[index]==nullptr)root->children[index]=new TrieNode(word[i]);
        root=root->children[index];
    }
    root->is_Terminal=true;
}

class Solution {
public:

    int search(TrieNode* root,int num){
        string word=to_string(num);
        int i,n=word.size();

        for(i=0;i<n;i++){
            int index=word[i]-'0';
            if(root->children[index])root=root->children[index];
            else return i;
        }
        return n;
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int i,n1=arr1.size(),n2=arr2.size(),ans=0;
        TrieNode* root=new TrieNode('-');

        for(i=0;i<n1;i++){
            insert(root,arr1[i]);
        }
        for(i=0;i<n2;i++){
            ans=max(ans,search(root,arr2[i]));
        }
        return ans;
    }
};