class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size())return false;
        char arr[260]={0};
        char count[260]={0};
        int i;
        for(i=0;i<s.size();i++){
            if( arr[s[i]]!=0  and arr[s[i]]!=t[i] )return false;
            else if(arr[s[i]]==0 and count[t[i]]==0){
                arr[s[i]]=t[i];
                count[t[i]]++;
                }
            else if(arr[s[i]]==0 )return false;
        }
        return true;
    }
};