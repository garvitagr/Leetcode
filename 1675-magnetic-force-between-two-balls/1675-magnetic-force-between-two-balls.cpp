class Solution {
public:
    bool check(vector<int>&position,int mid,int m){
        int ct=1,i,dist=0,last=0;
        for(i=0;i<position.size();i++){
            dist=abs(position[i]-position[last]);
            if(dist>=mid){
                dist=0;
                last=i;
                ct++;
            }
        }
        if(ct>=m)return true;
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int low=INT_MAX,high=position[position.size()-1]-position[0],i,ans=0,mid;
        for(i=0;i<position.size()-1;i++){
            low=min(low,(position[i+1]-position[i]));
        }
        while(low<=high){
            mid=low + (high-low)/2;
            if(check(position,mid,m))ans=mid,low=mid+1;
            else high=mid-1;
        }
        return ans;
    }
};