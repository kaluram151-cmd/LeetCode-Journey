class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int freq=0;
        int ans = 0;
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i]==1)
            {
                freq++;
                ans = max(ans,freq);
            }
            else
            {
                freq = 0;
            }
        }
        return ans;
    }
};