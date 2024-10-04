class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long sum=0,i,ans=0;
        map<int,int>mp;
        for(i=0;i<skill.size();i++)mp[skill[i]]++,sum+=skill[i];
        long long each=sum/(skill.size()/2);
        for(i=0;i<skill.size();i++){
            if(mp[skill[i]]){
                int rem=each-skill[i];
                if(rem==skill[i] and mp[rem]<2)return -1;
                if(mp[rem]){
                    ans+=rem*skill[i];
                    mp[rem]--;mp[skill[i]]--;
                }
                else return -1;
            }
        }
        return ans;
    }
};