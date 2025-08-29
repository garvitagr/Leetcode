class Solution {
public:
    long long flowerGame(int n, int m) {
        long long odd1,even1,odd2,even2,ans1=0,i,ans2=0;
        even1=n/2;
        even2=m/2;
        if(n&1)odd1=n/2 +1;
        else odd1=n/2;
        if(m&1)odd2=m/2 +1;
        else odd2=m/2;
        
//         cout<<even1<<odd1<<even2<<odd2<<endl;
        
//         if(even1>0){
//             ans=even1+odd2;
//         }
//         if(even2>0){
//             ans=max(ans,even2+odd1);
//         }
        
        
        for(i=1;i<=n;i++){
            if(i&1)ans1+=even2;
            else ans1+=odd2;
        }
        
         for(i=1;i<=m;i++){
            if(i&1)ans2+=even1;
            else ans2+=odd1;
        }
        
        
        return max(ans1,ans2);        
    }
};