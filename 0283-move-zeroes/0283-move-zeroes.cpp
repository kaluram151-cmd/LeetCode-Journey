class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int end = nums.size()-1;
        int i = 0;
        for(int i = 0;i<end;i++)
        {
            for(int j = 0;j<end;j++)
            {
                if(nums[j]==0)
                {
                    swap(nums[j], nums[j+1]);
                }
            }
            
        }
        return ;
    }
};