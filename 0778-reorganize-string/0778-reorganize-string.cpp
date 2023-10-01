class Solution {
public:
    string reorganizeString(string s) {
        map<char,int>mp;
        int i,maxi=INT_MIN;
        char ch;
        for(i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        for(auto it:mp){
            if(maxi<it.second){
                ch=it.first;
                maxi=it.second;
            }
        }
        i=0;
        while(i<s.size() and maxi){
            s[i]=ch;
            i+=2;
            maxi--;
        }
        if(maxi)return "";
        mp[ch]=0;

        for(auto it:mp){
            ch=it.first;
            maxi=it.second;
            while(maxi--){
             if(i>=s.size())i=1;
                s[i]=ch;
                i+=2;
            }
        }
        return s;     
    }
};