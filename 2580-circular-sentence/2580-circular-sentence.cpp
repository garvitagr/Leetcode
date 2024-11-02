class Solution {
public:
    bool isCircularSentence(string s) {
        vector<string>v;
        string temp;
        for(int i=0;i<s.size();i++){
            if(s[i]!=' ')temp+=s[i];
            else {
                v.push_back(temp);
                temp="";
            }
        }
        v.push_back(temp);
        for(int i=0;i<v.size()-1;i++){
            string s1=v[i],s2=v[i+1];
            if(s1.back()!=s2[0])return false;
        }
        if(v[0][0]!=v.back().back())return false;
        return true;
    }
};