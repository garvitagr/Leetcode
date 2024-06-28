class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        map<int,int>con;
        vector<int>v(n,0);
        long long i,ans=0;
        for(i=0;i<roads.size();i++)con[roads[i][0]]++,con[roads[i][1]]++;
        for(auto it:con)v[it.first]=(it.second);
        sort(v.begin(),v.end());
        for(i=0;i<v.size();i++){
            ans+=(i+1)*(v[i]);
        }
        return ans;
    }
};