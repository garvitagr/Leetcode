class Solution {
public:
    long long minimumSteps(string s) {
        long long ans=0;
        int ind=s.size()-1;
        vector<int>loc;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1')loc.emplace_back(i);
        }
        reverse(loc.begin(),loc.end());
        for(int i=0;i<loc.size();i++){
            ans+=ind-loc[i];
            ind--;
        }
        return ans;
    }
};