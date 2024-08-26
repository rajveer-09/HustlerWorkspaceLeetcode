class Solution:
    def findValidSplit(self, nums: List[int]) -> int:
        n = len(nums)
        left = 1
        i = 0        
        while i < n - 1:
            left *= nums[i]
            j = i + 1
            while j < n and math.gcd(left, nums[j]) == 1:
                j += 1
            if j == n:
                return i
            left *= math.prod(nums[i + 1:j])         
            i = j       
        return -1