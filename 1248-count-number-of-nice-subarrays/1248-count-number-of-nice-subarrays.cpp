class Solution {
public:
    int atmost(vector<int>& nums, int goal)
    {
        if(goal<0) return 0;
        int l = 0;
        int r = 0;
        int n = nums.size();
        int sum = 0;
        int count = 0;
        while(r<nums.size())
        {
            sum += (nums[r]);
            while(sum>goal)
            {
                sum -= (nums[l]);
                l = l+1;
            }
            count += (r-l+1);
            r++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i]%2==0)
            {
                nums[i] = 0;
            }
            else
            {
                nums[i] = 1;
            }
        }
        return atmost(nums,k)-atmost(nums,k-1);
    }
};