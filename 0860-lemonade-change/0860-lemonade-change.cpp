class Solution {
public:
    bool lemonadeChange(vector<int>& num) {
        int five = 0;
        int ten = 0;
        for(int i = 0;i<num.size();i++)
        {
            if(num[i]==5)
            {
                five++;
            }
            else if(num[i]==10)
            {
                ten++;
                if(five>=1)
                {
                    five--;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if(ten>=1 && five>=1)
                {
                    ten--;
                    five--;
                }
                else if(five>=3)
                {
                    five = five-3;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};