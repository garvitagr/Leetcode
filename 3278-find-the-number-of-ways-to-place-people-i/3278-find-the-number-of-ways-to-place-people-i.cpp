class Solution {
public:
    static bool cmp1(pair<int,int>a,pair<int,int>b){
        if(a.first!=b.first)return a.first<=b.first;
        else return a.second>=b.second;
    }
    
    int numberOfPairs(vector<vector<int>>& points) {
        int i,j,k,ans=0,ct,l1,l2,r1,r2,l3,r3;
        vector<pair<int,int>>v(points.size());
         for(i=0;i<points.size();i++){
             v[i].first=points[i][0];
             v[i].second=points[i][1];
         }
         sort(v.begin(),v.end(),cmp1);
        for(i=0;i<v.size();i++){
            l1=v[i].first;
            r1=v[i].second;
            
            
            for(j=i+1;j<v.size();j++){
                l2=v[j].first;
                r2=v[j].second;
                if(l2>=l1 and r1>=r2){
                    ans++;
                    for(k=i+1;k<j;k++){
                        l3=v[k].first;
                        r3=v[k].second;
                        if(l1<=l3 and l3<=l2 and r2<=r3 and r3<=r1){
                            ans--;
                            break;
                        }
                    }
                }
            }
            
        }
        return ans;        
    }
};