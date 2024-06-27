class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int i;
        map<int,int>mp;
        for(i=0;i<edges.size();i++)mp[edges[i][0]]++,mp[edges[i][1]]++;
        for(auto it:mp)if(it.second==edges.size())return it.first;
        return 1;
    }
};