/*
https://leetcodechina.com/problems/best-time-to-buy-and-sell-stock-ii/description/
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        
        //no chance for new trade
        if(len <= 1)
            return 0;
        
        int cur = prices[0];
        auto it = prices.begin();
        
        //phase 1: find the lowest buy price
        for(it++; it != prices.end(); it++){
            //the next one is lower, buy the new
            if(cur > *it){
                cur = *it;
                continue;
            }
            //else
            break;
        }
        
        if(it == prices.end())
            return 0;
        
        //phase 2: find best sell price
        int cmax = *it;
        it++;
        while(it != prices.end()){
            if(cmax < *it){
                cmax=*it;
                it++;
                continue;
            }
            //else
            break;
        }
        
        //phase 3: next loop
        if(prices.size() > 1){
            vector<int> t(it++, prices.end());
            return cmax - cur + maxProfit(t); 
        }
        else
            return cmax-cur;
    }
};