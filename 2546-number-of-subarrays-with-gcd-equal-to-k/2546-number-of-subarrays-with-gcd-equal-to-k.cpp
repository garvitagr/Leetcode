class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int n=nums.size(),i,j;
    map<int,int>prevends;
      map<int,int>freq;

    for(i=n-1;i>=0;i--){
        map<int,int>newends;
        for(auto it:prevends){
            int prevvalue=it.first;
            int prevend=it.second;
            int gcdval=__gcd(prevvalue,nums[i]);
            newends[gcdval]=max(prevend,newends[gcdval]);
        }
        newends[nums[i]]=max(i,newends[nums[i]]);
        prevends=newends;
        
        vector<pair<int,int>>v(newends.begin(),newends.end());
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