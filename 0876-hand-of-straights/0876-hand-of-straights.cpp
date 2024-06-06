class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0)return false;
        map<int,int>mp;
        int i;
        for(int i=0;i<hand.size();i++)mp[hand[i]]++;
        while(mp.size()){
            auto it=mp.begin();
            int num=it->first;
            for(int i=num;i<num+groupSize;i++){
                if(mp[i]==0)return false;
                mp[i]--;
                if(mp[i]==0)mp.erase(i);
            }
        }
        return true;
    }
};