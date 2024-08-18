#define ll long long
class Solution {
public:
    string removeKdigits(string s, int k) {
        ll i,curpos=0,n=s.size(),dig;
        string ans;
        vector<vector<ll>>pos(10);

        for(i=0;i<n;i++){
            pos[s[i]-'0'].emplace_back(i);
        }
        while(k>0){
            ll remain=n-curpos;
            if(remain==k){
                curpos=n;break;
            }
            for(dig=0;dig<=9;dig++){
                if(pos[dig].empty())continue;
                ll ind=lower_bound(pos[dig].begin(),pos[dig].end(),curpos)-pos[dig].begin();
                if(ind!=pos[dig].size())ind=pos[dig][ind];
                else continue;
                if(ind<=curpos+k){
                    k-=ind-curpos;
                    curpos=ind+1;
                    ans+=(dig+'0');
                    break;
                }
            }
        }
        while(curpos<n)ans+=s[curpos++];
        reverse(ans.begin(),ans.end());
        while(!ans.empty() and ans.back()=='0')ans.pop_back();
        reverse(ans.begin(),ans.end());
        return (ans.empty()?"0":ans);
    }
};