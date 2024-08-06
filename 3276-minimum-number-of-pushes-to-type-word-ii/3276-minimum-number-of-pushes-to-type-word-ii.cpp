class Solution {
public:
    int minimumPushes(string word) {
        int i,val=1,ct=0,ans=0;
        map<int,int>mp;
        for(i=0;i<word.size();i++)mp[word[i]]++;
        vector<pair<int,int>>v1;
        for(auto it:mp){
            v1.push_back(make_pair(it.second,it.first));
        }
        sort(v1.rbegin(),v1.rend());
        for(i=0;i<v1.size();i++){
            mp[v1[i].second]=val;
            ct++;
            if(ct==8){
                ct=0;val++;
            }
        }
        for(i=0;i<word.size();i++){
            ans+=mp[word[i]];            
        }
        return ans;
    }
};