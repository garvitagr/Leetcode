class Solution {
public:

    void comb(vector<vector<int>>&ans,vector<int>&candidates,vector<int>&ds,int target,int ind){
        if(ind>=candidates.size()){
           if(target==0) ans.push_back(ds);
            return;
        }
        int i;
        for(i=ind;i<candidates.size();i++){
             // take number :
        if(target-candidates[i]>=0){
            ds.push_back(candidates[i]);
            comb(ans,candidates,ds,target-candidates[i],i+1);
            ds.pop_back();
        }  

        // leave number :

        if(i>ind and candidates[i]==candidates[i-1]){
            // no take and call for i+1
            comb(ans,candidates,ds,target,i+1);
        }  
    }
}

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>ds;
        comb(ans,candidates,ds,target,0);
        return ans;
    }
};