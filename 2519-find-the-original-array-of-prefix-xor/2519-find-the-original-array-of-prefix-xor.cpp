class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int cur=pref[0],i;
        vector<int>ans;
        ans.push_back(pref[0]);

        for(i=1;i<pref.size();i++){
            cur=cur^pref[i];
            ans.push_back(cur);
            cur^=cur;
            cur^=pref[i];
        }
        return ans;
    }
};