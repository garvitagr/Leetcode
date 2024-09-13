class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int i,n=arr.size();
        vector<int>ans;
        vector<vector<int>>bits(n+1,vector<int>(32,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<32;j++){
                bits[i+1][j]=bits[i][j]+((arr[i]&(1<<j))==0?0:1);
            }
        }

        for(int i=0;i<queries.size();i++){
            int num=0;
            int x=queries[i][0];
            int y=queries[i][1];
            for(int j=0;j<32;j++){
                int ct=bits[y+1][j]-bits[x][j];
                if(ct&1){
                    num+=(1<<j);
                }
            }
            ans.push_back(num);
        }
        return ans;
    }
};