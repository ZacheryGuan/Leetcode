/*
https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/23/dynamic-programming/56/
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0], thisSum = nums[0];
        int len = nums.size();
        
        for(int i = 1; i<len; i++){
            if(thisSum < 0 && nums[i] > thisSum){
                thisSum = nums[i];
            }else
                thisSum += nums[i];
            
            if(thisSum > maxSum)
                maxSum = thisSum;
        }
        
        return maxSum;
    }
};