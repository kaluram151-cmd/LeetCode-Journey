class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        while(i<n)
        {
            if(i%2==0)
            {
                if(nums[i]<0)
                {
                    int p = i+1;
                    int x = nums[i];
                    while(p<n)
                    {
                        int y = nums[p];
                        if(nums[p]>=0)
                        {
                            nums[i] = nums[p];
                            nums[p] = x;
                            break;
                        }
                        nums[p] = x;
                        x = y;
                        p++;
                    }
                }
            }
            else
            {
                if(nums[i]>=0)
                {
                    int p = i+1;
                    int x = nums[i];
                    while(p<n)
                    {
                        int y = nums[p];
                        if(nums[p]<0)
                        {
                            nums[i] = nums[p];
                            nums[p] = x;
                            break;
                        }
                        nums[p] = x;
                        x = y;
                        p++;
                    }
                }
            }
            i++;
        }
        return nums;
    }
};