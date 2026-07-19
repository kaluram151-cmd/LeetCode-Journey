class Solution {
public:
    int getans(vector<int>& nums, int k)
    {
        if(k==0) return 0;
        int count = 0;
        int l = 0;
        int r = 0;
        int n = nums.size();
        unordered_map<int,int> mpp;
        while(r<n)
        {
            mpp[nums[r]]++;
            while(mpp.size()>k)
            {
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0)
                {
                    mpp.erase(nums[l]);
                }
                l++;
            }
            count = count+(r-l+1);
            r++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return getans(nums,k)-getans(nums,k-1);
    }
};