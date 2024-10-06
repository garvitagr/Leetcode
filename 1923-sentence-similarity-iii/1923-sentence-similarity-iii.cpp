class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        vector<string>word1,word2;
        string temp="";
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=' ')temp+=s1[i];
            else word1.push_back(temp),temp="";
        }
        word1.push_back(temp);
        temp="";
        for(int i=0;i<s2.size();i++){
            if(s2[i]!=' ')temp+=s2[i];
            else word2.push_back(temp),temp="";
        }
        word2.push_back(temp);
        temp="";
        if(word1.size()==word2.size())return word1==word2;
        if(word1.size()<word2.size()){
            int i=0,j=0,bi=word1.size()-1,bj=word2.size()-1;
            while(i<word1.size() and j<word2.size()){
                if(word1[i]==word2[j])i++,j++;
                else break;
            }
            if(i==word1.size())return true;
            i--;
            while(i!=bi and word1[bi]==word2[bj])bi--,bj--;
            return i==bi;
        }
        else{
            int i=0,j=0,bi=word1.size()-1,bj=word2.size()-1;;
            while(i<word1.size() and j<word2.size()){
                if(word1[i]==word2[j])i++,j++;
                else break;
            }
            if(j==word2.size())return true;
            j--;
            while(j!=bj and word1[bi]==word2[bj])bi--,bj--;
            return j==bj;
        }
    }
};