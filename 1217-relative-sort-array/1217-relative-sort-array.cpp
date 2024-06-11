class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int>mp1,mp2;
        int i;
        for(i=0;i<arr1.size();i++)mp1[arr1[i]]++;
        for(i=0;i<arr2.size();i++)mp2[arr2[i]]++;
        vector<int>ans;
        for(i=0;i<arr2.size();i++){
            int x=mp1[arr2[i]],j;
            for(j=0;j<x;j++)ans.push_back(arr2[i]),mp1[arr2[i]]--;
        }
        for(auto it:mp1){
            int x=it.second;
            while(x--)ans.push_back(it.first);
        }
        return ans;
    }
};