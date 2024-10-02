class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,int>mp;
        int ct=1;
        for(int i=0;i<arr.size();i++)mp[arr[i]]++;
        for(auto it:mp)mp[it.first]=ct++;
        vector<int>ans;
        for(int i=0;i<arr.size();i++)ans.emplace_back(mp[arr[i]]);
        return ans;
    }
};