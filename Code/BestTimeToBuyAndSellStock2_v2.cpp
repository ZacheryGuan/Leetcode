/*
https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/description/
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        int cmin = 0, cmax = 0;
        vector<int>::iterator it = prices.begin();
        int counter = 0, len = prices.size();
        
        //while there is >= two prices
        while(counter < len-1){
            cmin = prices[counter++];

            for( ;counter < len; counter++){
                if(cmin >= prices[counter])
                    cmin = prices[counter];
                else{
                    break;
                }
            }
            //now counter points to [higher price], or get the end of prices
            if(counter == len)
                break;
            //else
            cmax = -1;

            for( ;counter < len; counter++){
                if(cmax < prices[counter])
                    cmax = prices[counter];
                else
                    break;
            }
            result += cmax-cmin;
            
        }
        
        return result;
    }
};