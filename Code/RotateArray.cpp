/*
https://leetcodechina.com/explore/suan-fa/card/chu-ji-suan-fa/1/di-yi-zhang-jie/23/#
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        
        if(len <= 1)
            return;
        
        k = k % len;
        int t = 0;        
        
        //1. erase then push_back, repeat k
        for(int i = 0; i<k; i++){
            t = nums.back();
            nums.pop_back();
            nums.insert(nums.begin(), t);
        }
        //2. tmp=nums0, nums=nums+1, nums=tmp, repeat k
        
    }
};