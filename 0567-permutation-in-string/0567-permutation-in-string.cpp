class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int i,n1=s1.size(),n2=s2.size();
        if(n1>n2)return false;
        unordered_map<char,int>mp1,mp2;
        for(i=0;i<n1;i++)mp1[s1[i]]++;
        for(i=0;i<n1;i++)mp2[s2[i]]++;
        if(mp1==mp2)return true;
        for(i=n1;i<n2;i++){
            mp2[s2[i-n1]]--;
            if(mp2[s2[i-n1]]==0)mp2.erase(s2[i-n1]);
            mp2[s2[i]]++;
            if(mp1==mp2)return true;
        }
        return false;
    }
};