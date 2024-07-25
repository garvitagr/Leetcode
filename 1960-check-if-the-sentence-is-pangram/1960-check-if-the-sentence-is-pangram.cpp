class Solution {
public:
    bool checkIfPangram(string str) {
        map<char,int>mp;
        for(int i=0;i<str.size();i++){
           if(str[i]>='a' and str[i]<='z')mp[str[i]]++;
        }
        return mp.size()==26;
    }
};