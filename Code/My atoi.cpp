/*
https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/5/strings/37/
*/

class Solution {
public:
    int myAtoi(string str) {
        int i=-1, len=str.size();
        int res=0;
        int ifneg=1;
        while(i<len-1){
            i++;
            if(isspace(str[i]))
                continue;
            if(str[i]=='-'){
                ifneg=-1;
                i++;
            }
            else if(str[i]=='+'){
                ifneg=1;
                i++;
            }
            else if(!isdigit(str[i]))
                break;
            
            //valid input
            int digit=0;
            while(i<len){
                if(isdigit(str[i])){
                    res = res*10+str[i]-'0';
                    digit++;
                    if(res<0 || digit>10) 
                        // if(res == INT_MIN)
                        return ifneg==1?INT_MAX:INT_MIN;
                }
                else
                    return ifneg*res;
                i++;
            }
            
        }
        
        return ifneg*res;
    }
};