class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0)return false;
        map<int,int>mp;
        int i;
        for(int i=0;i<hand.size();i++)mp[hand[i]]++;

        for(auto [hand,freq]:mp){
            while(freq--){
                for(i=hand;i<hand+groupSize;i++){
                    if(mp[i]==0)return false;
                    mp[i]--;
                }
            }
        }
        return true;
    }
};