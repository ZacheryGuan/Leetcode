/*
https://leetcodechina.com/explore/suan-fa/card/chu-ji-suan-fa/1/di-yi-zhang-jie/21/
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int currentIndex = 0, length = 0;
        int tmpNum = 0;
        int originSize = nums.size();
        
        #initialize
        if(originSize > 0){
            tmpNum = nums[currentIndex];
            length++;
        }
        
        for(int currentIndex = 1; currentIndex < originSize; currentIndex++){            
            if(tmpNum == nums[currentIndex])    //Meet the same num as before
                continue;
            #else
            tmpNum = nums[currentIndex];
            nums[length] = tmpNum;
            length++;
        }
        
        return length;
    }
};