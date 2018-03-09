#leetcodechina.com/explore/suan-fa/card/chu-ji-suan-fa/1/di-yi-zhang-jie/26/
class Solution:
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        #sort
        nums1.sort()
        nums2.sort()
        
        #comapre length
        len1 = len(nums1)
        len2 = len(nums2)
        
        if len1>len2:  #make nums1 shorter
            tmpNums = nums1
            nums1 = nums2
            nums2 = tmpNums
            tmpLen = len1
            len1 = len2
            len2 = tmpLen
        
        #find intersection
        result = []
        matchedIndex = 0
        ifNexti = False
        for i in range(len1):
            for j in range(matchedIndex, len2):
                if nums1[i]==nums2[j]:
                    result.append(nums1[i])
                    matchedIndex = j+1
                    ifNexti = True
                    break
                elif nums1[i]<nums2[j]:
                    ifNexti = True
                    break
                else:   #nums1[i]>nums2[j]
                    continue
            if ifNexti == True:
                continue
        
        return result
            