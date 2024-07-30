class Solution {
public:
    bool find(unordered_map<char,int>&mp,int k){
        for(auto &it:mp)if(it.second<k)return 0;
        return 1;
    }

    int longestSubstring(string s, int k) {
        int i,n=s.size(),ans=0;
        map<int,int>unique;
        for(i=0;i<n;i++)unique[s[i]]++;

        for(i=1;i<=unique.size();i++){
            unordered_map<char,int>mp;
            int st=0,size=0;
            while(st<n){
                mp[s[st]]++;size++;
                while(mp.size()>i){
                    mp[s[st-(size-1)]]--;
                    if(mp[s[st-(size-1)]]==0)mp.erase(s[st-(size-1)]);
                    size--;
                }
                if(find(mp,k))ans=max(ans,size);
                st++;
            }
        }
        return ans;
    }
};