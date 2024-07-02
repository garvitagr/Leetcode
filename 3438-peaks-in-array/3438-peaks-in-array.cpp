#define ll long long
class SGTREE{
public:   
   vector<ll>seg;
   // seg vector size-> seg[4*n];
   SGTREE(ll n){
      seg.resize(4*n+1);
   }

   void build(ll ind,ll low,ll high,vector<int>&arr){
   
   // initial build call -> build(0,0,n-1,arr);
   if(low==high){
      seg[ind]=arr[low];
      return;
   }

   ll mid=(low+high)/2;
   build(2*ind+1,low,mid,arr);
   build(2*ind+2,mid+1,high,arr);

   seg[ind]=(seg[2*ind+1]+seg[2*ind+2]);
}

ll query(ll ind,ll low,ll high,ll l,ll r){
    if(l>r)return 0;
    // l and r refers to query range
   // ind refers to the segment node index 

    // no overlap
    // l r low high or low high l r
    if(r<low or high<l)return 0;

  // complete overlap // when range contains all this nodes indexes
   // l low high r 
    if(low>=l and high<=r)return seg[ind];

    ll mid=(low+high)>>1;
    ll left=query(2*ind+1,low,mid,l,r);
    ll right=query(2*ind+2,mid+1,high,l,r);

    return (left+right);
}

void update(ll ind,ll low,ll high,ll i,ll val){
      if(low==high){
         seg[ind]=val;
         return;
      }
      ll mid=(low+high)>>1;

      if(i<=mid)update(2*ind+1,low,mid,i,val);
      else update(2*ind+2,mid+1,high,i,val);

      seg[ind]=(seg[2*ind+1]+seg[2*ind+2]);
   }

};

class Solution {
public:
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        int i,n=nums.size();
        vector<int>peaks(n,0),ans;
        
        for(i=1;i<n-1;i++){
            if(nums[i-1]<nums[i] and nums[i]>nums[i+1])peaks[i]=1;
        }
        SGTREE sg(n);
        sg.build(0,0,n-1,peaks);
        
        for(i=0;i<queries.size();i++){
            if(queries[i][0]==2){
                int index=queries[i][1];
                int val=queries[i][2];
                if(index==0 or index==n-1){
                    nums[index]=val;
                    if(index==0){
                        if(index+2<n and nums[index]<nums[index+1] and nums[index+1]>nums[index+2]){
                            sg.update(0,0,n-1,index+1,1);
                            peaks[index+1]=1;
                        }
                        else if(index+2<n){
                            sg.update(0,0,n-1,index+1,0);
                            peaks[index+1]=0;
                        }
                    }
                    else{
                        if(index-2>=0 and nums[index-2]<nums[index-1] and nums[index-1]>nums[index]){
                            sg.update(0,0,n-1,index-1,1);
                            peaks[index-1]=1;
                        }
                        else if(index-2>=0){
                            sg.update(0,0,n-1,index-1,0);
                            peaks[index-1]=0;
                        }
                    }
                }
                else{
                    nums[index]=val;
                    // update the ind
                    if(nums[index-1]<nums[index] and nums[index]>nums[index+1]){
                        // update index to 1 in seg tree ????????
                        sg.update(0,0,n-1,index,1);
                        peaks[index]=1;
                    }
                    else {
                        // update index to 0 in seg tree ????????
                        sg.update(0,0,n-1,index,0);
                        peaks[index]=0;
                    }
                    // update the ind-1
                    if(index-1!=0){
                        if(nums[index-2]<nums[index-1] and nums[index-1]>nums[index]){
                            // update index-1 to 1 in seg tree ????????
                            sg.update(0,0,n-1,index-1,1);
                            peaks[index-1]=1;
                        }   
                        else {
                            // update index-1 to 0 in seg tree ????????
                            sg.update(0,0,n-1,index-1,0);
                            peaks[index-1]=0;
                        }
                    }

                    // update the ind+1

                    if(index+1!=n-1){
                        if(nums[index]<nums[index+1] and nums[index+1]>nums[index+2]){
                            // update index+1 to 1 in seg tree ????????
                            sg.update(0,0,n-1,index+1,1);
                            peaks[index+1]=1;
                        }   
                        else {
                            // update index+1 to 0 in seg tree ????????
                            sg.update(0,0,n-1,index+1,0);
                            peaks[index+1]=0;
                        }
                    }
                }
            }
            else {
                int l=queries[i][1];
                int r=queries[i][2];
                ans.push_back(sg.query(0,0,n-1,l+1,r-1));
            }
        }

        return ans;
    }
};