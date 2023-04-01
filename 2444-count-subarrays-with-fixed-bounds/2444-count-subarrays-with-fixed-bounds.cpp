class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        
        int min_idx = -1 , max_idx = -1 , last_invalid_idx = -1;
        long long ans = 0;

        for(int i = 0 ; i < nums.size() ; i++) {
            if(nums[i] < minK || nums[i] > maxK) 
                last_invalid_idx = i;
            if(nums[i] == minK)
                min_idx = i;
            if(nums[i] == maxK)
                max_idx = i;
            ans = ans + max(0 , (min(min_idx , max_idx) - last_invalid_idx));
        }

        return ans;
    }
};