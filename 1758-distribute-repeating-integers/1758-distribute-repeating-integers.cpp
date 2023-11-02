class Solution {
public:
    bool recur(vector<int>&count,vector<int>&quantity,int i){
        // base case
        if(i>=quantity.size())return true;

        int j;
        for(j=0;j<count.size();j++){
            if(count[j]>=quantity[i]){
                count[j]-=quantity[i];
                if(recur(count,quantity,i+1)==false){
                    // then backtrack
                    count[j]+=quantity[i];
                }
                else return true;
            }
        }
        return false;


    }

    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        sort(quantity.rbegin(),quantity.rend());
        unordered_map<int,int>mp;
        int i;
        for(i=0;i<nums.size();i++)mp[nums[i]]++;
        vector<int>count;
        for(auto it:mp){
            count.push_back(it.second);
        }
        return recur(count,quantity,0);
    }
};