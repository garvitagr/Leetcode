class Solution {
public:
    int findTheLongestSubstring(string s) {
        map<string,int>mp;
        mp["00000"]=-1;
        vector<int>state(5,0);
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a')state[0]++;
            if(s[i]=='e')state[1]++;
            if(s[i]=='i')state[2]++;
            if(s[i]=='o')state[3]++;
            if(s[i]=='u')state[4]++;
            string curstate;
            for(int j=0;j<5;j++){
                state[j]%=2;
                curstate+=to_string(state[j]);
            }
            if(mp.find(curstate)!=mp.end()){
                ans=max(ans,i-mp[curstate]);
            }
            else mp[curstate]=i;
        }
        return ans;
    }
};