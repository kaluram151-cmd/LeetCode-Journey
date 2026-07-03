class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int end = nums.size()-1;
        int start = 0;
        while(start<=end)
        {
            if(nums[start]==0)
            {
                for(int i = start;i<end;i++)
                {
                    nums[i] = nums[i+1];
                }
                nums[end] = 0;
                end--;
            }
            else
            {
                start++;
            }
        }
        return ;
    }
};