/*
https://leetcodechina.com/explore/suan-fa/card/chu-ji-suan-fa/1/di-yi-zhang-jie/29/
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        int i, j, t=0;
        bool isFind = false;
        for(i = 0; i<len; i++){
            if(true){    //use"=" since there will be 0 or negtives
                t = target - nums[i];
                for(j = i+1; j<len; j++){
                    if(nums[j]==t){
                        isFind = true;
                        break;
                    }
                }
            }
            if(isFind)
                break;
        }
        
        vector<int> res;
        res.push_back(i);
        res.push_back(j);
        return res;
    }
};