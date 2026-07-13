class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
        {
            return 0;
        }
        long long sum = 0;
        for(int i = 0; i<n;i++)
        {
            long long x = nums[i];
            long long y = nums[i];
            for(int j = i+1;j<n;j++)
            {
                x = max<long long>(nums[j], x);
                y = min<long long>(nums[j], y);
                sum += x-y;
            }
        }
        return sum;
    }
};