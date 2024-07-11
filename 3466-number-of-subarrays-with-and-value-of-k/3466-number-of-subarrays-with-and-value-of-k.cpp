#define ll long long
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
    ll n=nums.size(),i,j;
    map<ll,ll>prevends;
      map<ll,ll>freq;

    for(i=n-1;i>=0;i--){
        map<ll,ll>newends;
        for(auto it:prevends){
            ll prevandvalue=it.first;
            ll prevandend=it.second;
            newends[prevandvalue&nums[i]]=max(prevandend,newends[prevandvalue&nums[i]]);
        }
        newends[nums[i]]=max(i,newends[nums[i]]);
        prevends=newends;

        
        vector<pair<ll,ll>>v(newends.begin(),newends.end());
        reverse(v.begin(),v.end());
        for(j=0;j<v.size();j++){
            if(j==0){
               freq[v[j].first]+=(v[j].second-i+1);
            }
            else{
               freq[v[j].first]+=(v[j].second-(v[j-1].second+1)+1);
            }
        }
    }
    return freq[k];
    }
};