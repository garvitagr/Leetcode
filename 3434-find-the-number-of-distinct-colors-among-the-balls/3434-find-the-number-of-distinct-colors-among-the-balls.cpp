class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int>ans;
        map<int,int>mp1,mp2;
        int i;
        for(i=0;i<queries.size();i++){
            if(mp1.find(queries[i][0])!=mp1.end()){
                mp2[mp1[queries[i][0]]]--;
                if(mp2[mp1[queries[i][0]]]==0)mp2.erase(mp1[queries[i][0]]);
                mp1[queries[i][0]]=queries[i][1];
                mp2[queries[i][1]]++;                
            }
            else{
                mp1[queries[i][0]]=queries[i][1];
                mp2[queries[i][1]]++;  
            }
            ans.push_back(mp2.size());
        }
        return ans;
    }
};