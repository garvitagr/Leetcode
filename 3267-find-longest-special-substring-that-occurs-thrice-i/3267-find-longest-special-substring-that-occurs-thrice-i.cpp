class Solution {
public:
    void FillLps(string &pat,vector<int>&lps){
        int n=pat.size();
        int len=0;
        int i=1;
        lps[0]=0;

        while(i<n){
            if(pat[i]==pat[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len==0){
                    lps[i]=0;
                    i++;
                }
                else len=lps[len-1];
            }
        }
    }

    int kmp(string &str, string &pat) {
        int n=str.size();
        int m=pat.size();
        if(m==0)return 0;  // when we wants count of substrings in this string
        vector<int>lps(m,0);
        vector<int>index;
        FillLps(pat,lps);
        int i=0,j=0;
        while(i<n){
            if(str[i]==pat[j]){
                i++;j++;
                if(j==m){
                    // starting index of matching pat
                    index.push_back(i-j);
                    j=lps[j-1];
                }
            }
            else {
                if(j==0)i++;
                else j=lps[j-1];
            }
        }
        if(index.empty())return -1;
        return index.size();
    }
    bool check(string &s){
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++)mp[s[i]]++;
        return mp.size()==1;
    }
    int maximumLength(string s) {
        int i,j,k,n=s.size(),ans=0;
        for(i=0;i<n;i++){
            for(j=i;j<n;j++){
                string temp=s.substr(i,j-i+1);
                if(!check(temp))break;
                int times=kmp(s,temp);
                int sz=temp.size();
                if(times>=3)ans=max(ans,sz);
            }
        }
        return (ans==0?-1:ans);
    }
};