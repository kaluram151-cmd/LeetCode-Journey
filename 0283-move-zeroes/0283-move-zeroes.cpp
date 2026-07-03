class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int end = nums.size()-1;
        for(int i = end;i>=0;i--)
        {
            if(nums[i]==0)
            {
                for(int j = i;j<end;j++)
                {
                    if(nums[j]==0)
                    {
                        swap(nums[j],nums[j+1]);
                    }
                }
                end--;
            }
        }   
        return ;
    }
};