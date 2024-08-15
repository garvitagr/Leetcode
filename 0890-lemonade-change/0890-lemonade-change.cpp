class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0,ten=0,i;
        for(i=0;i<bills.size();i++){
            if(bills[i]==5)five++;
            else {
                int change=bills[i]-5;
                if(change==5){
                    if(!five)return false;
                    five--;
                }
                if(change==15){
                    if(ten and five)ten--,five--;
                    else if(five>=3)five-=3;
                    else return false;
                }                
                if(bills[i]==10)ten++;
            }
        }
        return true;
    }
};