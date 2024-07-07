class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int drink=0;
        while(numBottles>=numExchange){
            numBottles-=numExchange;
            numBottles++;
            drink+=numExchange;
        }
        drink+=numBottles;
        
        return drink;

    }
};